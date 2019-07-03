// Consumer

#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

#include <unistd.h>
#include <sys/types.h>

#include <semaphore.h>

// $ gcc Consumer.c -lrt -pthread -o 'Consumer.out'

int buffer_size = 10;

struct shared_mem
{
	sem_t mutex, full, empty;
	int buffer[10];
};

void main () {

	struct shared_mem *d;
	int ch=0, full, empty, consumed;

	int fd = shm_open("/shared_mem", O_RDWR, 777);
	ftruncate(fd, sizeof(struct shared_mem));
	d = (struct shared_mem *)mmap(NULL, sizeof(struct shared_mem), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	while(1)
	{
		
		sem_getvalue(&(d->empty), &empty);

		if (empty < buffer_size)
		{
			sem_wait(&(d->mutex));
			sem_wait(&(d->full));

			sem_getvalue(&(d->full), &full);
			consumed = d->buffer[full];
			printf("\nConsumed value %d at %d", consumed, full);

			sem_post(&(d->empty));
			sem_post(&(d->mutex));
		}
		else
		{
			printf("\nCannot consume, buffer is empty !");
		}

		printf("\nPress any number to continue (0 to quit) : ");
		scanf("%d", &ch);
		if (ch == 0)
		{	
		    munmap(d, sizeof(struct shared_mem));
			shm_unlink("/shared_mem");
			printf("\nExiting");
			break;
		}
	}
}
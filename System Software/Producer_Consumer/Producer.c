// Producer

#include <stdio.h>
#include <stdlib.h>

#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

#include <unistd.h>
#include <sys/types.h>

#include <semaphore.h>

// $ gcc Producer.c -lrt -pthread -o 'Producer.out'

int buffer_size = 10;

struct shared_mem
{
	sem_t mutex, full, empty;
	int buffer[10];
};

void main () {

	struct shared_mem *d;
	int ch=0, full, produced = 100;

	int fd = shm_open("/shared_mem", O_CREAT|O_RDWR, 777);
	ftruncate(fd, sizeof(struct shared_mem));
	d = (struct shared_mem *)mmap(NULL, sizeof(struct shared_mem), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    
	sem_init(&(d->empty), 1, 10);
	sem_init(&(d->mutex), 1, 1);
	sem_init(&(d->full), 1, 0);
	

	while(1)
	{
		sem_getvalue(&(d->full), &full);
 
		if (full < buffer_size)
		{
			sem_wait(&(d->mutex));
			sem_wait(&(d->empty));

			d->buffer[full] = produced++;
			printf("\nProduced value %d at %d", d->buffer[full], full);

			sem_post(&(d->full));
			sem_post(&(d->mutex));
		}
		else
		{
			printf("\nCannot produce, buffer is full !");
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
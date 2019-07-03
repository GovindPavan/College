// To implement Banker's Algorithm

#include <stdio.h>
#include <stdlib.h>


int less_than_or_equal_to (int n, int mat1[n], int mat2[n])
{
	int flag = 1;
	for(int i=0; i<n; i++)
	{
		if (mat1[i] <= mat2[i]) continue;
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
}


void print_state(int n, int m, int available[m], int max[n][m], int allocation[n][m], int need[n][m])
{
	printf("\nAllocation\tMax\t\tNeed \n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d  ", allocation[i][j]);
		}
		printf("\t");
		for(int k=0; k<m; k++)
		{
			printf("%d  ", max[i][k]);
		}
		printf("\t");
		for(int l=0; l<m; l++)
		{
			printf("%d  ", need[i][l]);
		}
		printf("\n");
	}

	printf("\nAvailable : ");
	for(int i=0; i<m; i++)
		printf("%d  ", available[i]);
}


int is_state_safe (int n, int m, int available[m], int allocation[n][m], int need[n][m])
{
	// Safety Algorithm
	int safe_state = 1; // 1 means safe

	int *work = (int *)malloc(m*sizeof(int));
	int *finish = (int *)malloc(n*sizeof(int));

	for (int i=0; i<m; i++) work[i] = available[i];
	for (int i=0; i<n; i++) finish[i] = 0;

	for (int i=0, count=0; count < n; i++)
	{
		i = i % n; // for selecting a process i
		count++;
		if (finish[i] == 0 && less_than_or_equal_to(m, need[i], work))
		{
			for(int j=0; j<m; j++)
				work[j] += allocation[i][j];
			finish[i] = 1;
			count = 0;
		}
	}

	// Final checking ...
	for (int i=0; i<n; i++)
	{
		if (finish[i] == 0)
		{	
			// System is not in a safe state :(
			safe_state = 0;
			break;
		}	
	}

	free(work);
	free(finish);
	return safe_state;
}

void main()
{
	/* ------------- Declaring and initializing required Data Structures ------------- */
	int n; // Number of processes
	printf("\nEnter number of processes : ");
	scanf("%d", &n);

	int m; // Number of resource types
	printf("\nEnter number of resource types : ");
	scanf("%d", &m);
	
	// available[resource i] = k instances
	int *available = (int *)malloc(m*sizeof(int));
	printf("\nPlease enter the number of instances available for each resource types : ");
	for(int i=0; i<m; i++)
	{
		printf("\nNumber of instances of Resource Type #%d : ", i+1);
		scanf("%d", &available[i]);
	}

	// max[process i][resource j] = k instances of [resource j] will be requested by [process i] at max
	int max[n][m];
	printf("\nPlease enter the maximum number of instances of resource types required for each process : ");
	for(int i=0; i<n; i++)
	{
		printf("\nFor process #%d", i+1);
		for(int j=0; j<m; j++)
		{
			printf("\nNumber of instances of Resource Type #%d : ", i+1);
			scanf("%d", &max[i][j]);
		}
	}

	// allocation[process i][resource j] = k instances of [resource j] are currently allocated to [process i]
	int allocation[n][m];
	printf("\nPlease enter the number of instances of resource types allocated for each process : ");
	for(int i=0; i<n; i++)
	{
		printf("\nFor process #%d", i+1);
		for(int j=0; j<m; j++)
		{
			printf("\nNumber of instances of Resource Type #%d : ", i+1);
			scanf("%d", &allocation[i][j]);
		}
	}

	// need[process i][resource j] = process[i] neeeds k more instances of [resource j]
	int need[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			need[i][j] = max[i][j] - allocation[i][j];
		
	print_state(n, m, available, max, allocation, need);


	/* ------------ Implementing algorithm ------------- */
	if ( is_state_safe(n, m, available, allocation, need) )
	{
		printf("\nThe system is currently in a Safe State !");
		int choice=1, pid;
		do {
			// The Request
			printf("\nEnter the process ID of the requesting process : ");
			scanf("%d", &pid);
			pid--;

			int *request = (int *)malloc(m*sizeof(int));
			printf("\nPlease enter the new request for the number of instances for each resource types : ");
			for(int i=0; i<m; i++)
			{
				printf("\nNumber of instances of Resource Type #%d : ", i+1);
				scanf("%d", &request[i]);
			}
			
			// Resource-Request Algorithm
			if( less_than_or_equal_to(m, request, need[pid]) )
			{
				if ( less_than_or_equal_to(m, request, available) )
				{
					printf("\nProcessing your request ... ");
					for(int j=0; j<m; j++) 
					{
						available[j] -= request[j];
						allocation[pid][j] += request[j];
						need[pid][j] -= request[j];
					}
					if ( is_state_safe(n, m, available, allocation, need) )
					{	
						printf("\nYour request was processed succesfully !");
						print_state(n, m, available, max, allocation, need);
					}	
					else
					{
						printf("\nAccepting the request will lead to an unsafe state ... reverting to a safe state.");
						// Reverting
						for(int j=0; j<m; j++) 
						{
							available[j] += request[j];
							allocation[pid][j] -= request[j];
							need[pid][j] += request[j];
						}
					}
				}
				else
				{
					printf("\nThe request cannot be satisfied because the requested resource instances exceeds the available instances !");
					printf("\nAvailable : ");
					for(int i=0; i<m; i++)  printf("%d  ", available[i]);
				}
			}
			else
			{
				printf("\nThe process's request exceeded its claimed need !");
				printf("\nProcess #%d's Need : ", pid+1);
				for(int i=0; i<m; i++)  printf("%d  ", need[pid][i]);
			}

			printf("\nDo you want to continue ? (1/0) : ");
			scanf("%d", &choice);
		}while (choice == 1);
	}
	else
	{
		printf("\nThis state is not a Safe State !");
	}
}
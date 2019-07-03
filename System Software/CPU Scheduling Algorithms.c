/* To Implement the following CPU Scheduling Algorithms: 
	1. First Come First Served (FCFS)
	2. Shortest Job First (SJF)
	3. Round Robin
	4. Priority Scheduling 
WARNING : Arrival Time is not implemented and thus it is considered for all processes as 0.
gcc version 7.2.0                                                                              */


#include <stdio.h>
#include <stdlib.h>

// Process Control Block (PCB) Structure
struct process
{
	int pid;
	int priority;
	float burst_time;
	float arrival_time;
	float waiting_time;
	float turn_arround_time;
};


// Funtion to imlement FCFS Scheduling
struct process* FCFS (struct process *rq_ptr, int n)
{
	rq_ptr[0].turn_arround_time = rq_ptr[0].waiting_time + rq_ptr[0].burst_time;

	for (int i=1; i<n; i++)
	{
		rq_ptr[i].waiting_time = rq_ptr[i-1].turn_arround_time;
		rq_ptr[i].turn_arround_time = rq_ptr[i].waiting_time + rq_ptr[i].burst_time;
	}

	return rq_ptr;
}

struct process* SJF (struct process *rq_ptr, int n)
{
	// Selectively sorting using burst time
	float shortest_BT;
	int shortest_pid;
	struct process temp;
	for (int i=0; i<n; i++)
	{
		// Assuming the first process as the shortest process
		shortest_BT = rq_ptr[i].burst_time;
		shortest_pid = i;
		// Finding the shortest process
		for(int j=i+1; j<n; j++)
		{
			if (rq_ptr[j].burst_time < shortest_BT)
			{
				shortest_BT = rq_ptr[j].burst_time;
				shortest_pid = j;
			}
		}
		// If our assumption is wrong
		if (shortest_pid != i)
		{
			// Swap
			temp = rq_ptr[i];
			rq_ptr[i] = rq_ptr[shortest_pid];
			rq_ptr[shortest_pid] = temp;
		}
	}

	rq_ptr[0].turn_arround_time = rq_ptr[0].waiting_time + rq_ptr[0].burst_time;
	for (int i=1; i<n; i++)
	{
		rq_ptr[i].waiting_time = rq_ptr[i-1].turn_arround_time;
		rq_ptr[i].turn_arround_time = rq_ptr[i].waiting_time + rq_ptr[i].burst_time;
	}

	return rq_ptr;
}

struct process* round_robin (struct process *rq_ptr, int n, float time_slice)
{
	float tic_toc = 0.0;
	int finished_processes = 0;
	
	for(int i=0; finished_processes < n ; i++)
	{
		i = i%n;
		// While this loop runs ... turn_arround_time stores the time in which the process is assigned to a processor for execution.
		if (rq_ptr[i].burst_time > time_slice)
		{
			rq_ptr[i].waiting_time = tic_toc - rq_ptr[i].turn_arround_time;
			// The process executes
			tic_toc += time_slice;
			rq_ptr[i].burst_time -= time_slice;
			rq_ptr[i].turn_arround_time += time_slice;
		} 
		else if (rq_ptr[i].burst_time == 0.0) continue;
		else
		{
			rq_ptr[i].waiting_time = tic_toc - rq_ptr[i].turn_arround_time;
			tic_toc += rq_ptr[i].burst_time;
			rq_ptr[i].burst_time -= rq_ptr[i].burst_time;
			rq_ptr[i].turn_arround_time = tic_toc - rq_ptr[i].arrival_time;
			finished_processes++;
		}
	}
	return rq_ptr;
}


struct process* priority_scheduling (struct process *rq_ptr, int n)
{
	// Selectively sorting using priority
	float highest_priority;
	int priority_pid;
	struct process temp;
	for (int i=0; i<n; i++)
	{
		// Assuming the first process as the shortest process
		highest_priority = rq_ptr[i].priority;
		priority_pid = i;
		// Finding the shortest process
		for(int j=i+1; j<n; j++)
		{
			if (rq_ptr[j].priority < highest_priority)
			{
				highest_priority = rq_ptr[j].priority;
				priority_pid = j;
			}
		}
		// If our assumption is wrong
		if (priority_pid != i)
		{
			// Swap
			temp = rq_ptr[i];
			rq_ptr[i] = rq_ptr[priority_pid];
			rq_ptr[priority_pid] = temp;
		}
	}

	rq_ptr[0].turn_arround_time = rq_ptr[0].waiting_time + rq_ptr[0].burst_time;
	for (int i=1; i<n; i++)
	{
		rq_ptr[i].waiting_time = rq_ptr[i-1].turn_arround_time;
		rq_ptr[i].turn_arround_time = rq_ptr[i].waiting_time + rq_ptr[i].burst_time;
	}

	return rq_ptr;
}

// Funtion to print the final results
void print_result (struct process *rq_ptr, int n)
{
	float avg_waiting_time = 0.0;
	float avg_turn_arround_time = 0.0;

	printf("\n------------ Result ------------");
	for (int i=0; i<n; i++)
	{
		printf("\nProcess ID : %d", rq_ptr[i].pid);
		printf("\nWaiting Time : %f", rq_ptr[i].waiting_time);
		avg_waiting_time += rq_ptr[i].waiting_time;
		printf("\nTurn Arround Time : %f", rq_ptr[i].turn_arround_time);
		avg_turn_arround_time += rq_ptr[i].turn_arround_time;
	}

	avg_waiting_time /= n;
	avg_turn_arround_time /= n;

	printf("\n*Average Waiting Time = %f", avg_waiting_time);
	printf("\n*Average Turn Arround Time = %f", avg_turn_arround_time);
}

void main ()
{
	int n;
	printf("\nEnter the number of processes : ");
	scanf("%d",&n);

	struct process *ready_queue_ptr = (struct process *)malloc(n*sizeof(struct process));

	// Accepting the processes to a temporary queue
	struct process *temp_rq_ptr = (struct process *)malloc(n*sizeof(struct process));

	for (int i=0; i<n; i++)
	{
		temp_rq_ptr[i].pid = i+1;
		printf("\nEnter details of Process#%d", i+1);
		printf("\nPriority : ");
		scanf("%d", &temp_rq_ptr[i].priority);
		printf("\nBurst Time : ");
		scanf("%f", &temp_rq_ptr[i].burst_time);
		temp_rq_ptr[i].arrival_time = 0.0;
	}

	// Displaying the process list
	printf("\n------------ Process List ------------");
	for (int i=0; i<n; i++)
	{
		printf("\nProcess ID : %d", temp_rq_ptr[i].pid);
		printf("\nPriority : %d", temp_rq_ptr[i].priority);
		printf("\nBurst Time : %f", temp_rq_ptr[i].burst_time);
		printf("\nArrival Time : %f\n", temp_rq_ptr[i].arrival_time);
	}

	int choice;
	float time_slice;
	// Main loop
	do
	{
		// Selecting a scheduling algorithm
		printf("\n------------ MENU ------------");
		printf("\n1. FCFS\n2. SJF\n3. Round Robin\n4. Priority Scheduling\n5. Exit");
		printf("\nEnter your choice : ");
		scanf("%d", &choice);

		// Initializing the Ready Queue
		if (choice < 5)
		{
			for (int i=0; i<n; i++)
			{
				ready_queue_ptr[i].pid = temp_rq_ptr[i].pid;
				ready_queue_ptr[i].priority = temp_rq_ptr[i].priority;
				ready_queue_ptr[i].burst_time = temp_rq_ptr[i].burst_time;
				ready_queue_ptr[i].arrival_time = temp_rq_ptr[i].arrival_time;
				ready_queue_ptr[i].waiting_time = 0.0;
				ready_queue_ptr[i].turn_arround_time = 0.0;
			}
		}

		switch (choice)
		{
			case 1 :ready_queue_ptr = FCFS(ready_queue_ptr, n);
					print_result(ready_queue_ptr, n);
					break;
			case 2 :ready_queue_ptr = SJF(ready_queue_ptr, n);
					print_result(ready_queue_ptr, n);
					break;
			case 3 :printf("\nEnter the time slice : ");
					scanf("%f", &time_slice);
					ready_queue_ptr = round_robin(ready_queue_ptr, n, time_slice);
					print_result(ready_queue_ptr, n);
					break;
			case 4 :ready_queue_ptr = priority_scheduling(ready_queue_ptr, n);
					print_result(ready_queue_ptr, n);
					break;
			case 5 :printf("\nThank you !\n");
					exit(0);
					break;
			default: printf("\nPlease select one of 5 options.");
		}
	}while(1);
}
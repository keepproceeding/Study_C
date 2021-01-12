#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 20

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;
void error(char* msg)
{
	printf("%s\n", msg);
	exit(1);
}
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
int is_empty(QueueType* q)
{
	return(q->front == q->rear);
}
int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("queue full\n");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
element dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("queue empty\n");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
int main(void) {
	int minutes = 60;
	int total_wait = 0;
	int total_customer = 0;
	int service_time1 = 0;
	int service_time2 = 0;
	int service_customer1, service_customer2;
	QueueType queue;

	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("current time = %d\n", clock);
	
		//in

		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("customer:%d,arrival time:%d, service time : %d",
				customer.id, customer.arrival_time, customer.service_time);
		}

		//service
		if (service_time1 > 0 && service_time2>0) {
			printf("\nservicing customer : %d & %d\n", service_customer1,service_customer2);
			service_time1--;
			service_time2--;
		}//free
		else if (service_time1 > 0 && service_time2 == 0) {
			service_time1--;
			if (!is_empty(&queue)) {
				element customer2 = dequeue(&queue);
				service_customer2 = customer2.id;
				service_time2 = customer2.service_time;
				printf("customer %d, ,section : 2, start time : %d, wait time: %d\n",
					customer2.id, clock, clock - customer2.arrival_time);
				total_wait += clock - customer2.arrival_time;
			}
		}
		else if (service_time1 == 0 && service_time2 > 0) {
			service_time2--;
			if (service_time2 > 0) {
				service_time2--;
				if (!is_empty(&queue)) {
					element customer1 = dequeue(&queue);
					service_customer1 = customer1.id;
					service_time1 = customer1.service_time;
					printf("customer %d,section: 1, start time : %d, wait time: %d\n",
						customer1.id, clock, clock - customer1.arrival_time);
					total_wait += clock - customer1.arrival_time;
				}
			}

		}
		else {
			if (!is_empty(&queue)) {
				element customer1 = dequeue(&queue);
				service_customer1 = customer1.id;
				service_time1 = customer1.service_time;
				printf("customer %d, section :1, start time : %d, wait time: %d\n",
					customer1.id, clock, clock - customer1.arrival_time);
				total_wait += clock - customer1.arrival_time;
			}
			if (!is_empty(&queue)) {
				element customer2 = dequeue(&queue);
				service_customer2 = customer2.id;
				service_time2 = customer2.service_time;
				printf("customer %d, section : 2, start time : %d, wait time: %d\n",
					customer2.id, clock, clock - customer2.arrival_time);
				total_wait += clock - customer2.arrival_time;
			}
		}
	}
	printf("total wait time=%d\n", total_wait);
	return 0;
}

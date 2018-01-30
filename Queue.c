#include<stdio.h>
#include<stdlib.h>

typedef struct 
{

	int front, rear, size;
	int capacity;
	int* array;
}Queue;


Queue* createQueue(int capacity)
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));

	queue -> front = 0;
	queue -> size  = 0;
	queue -> rear  = -1;
	queue -> array = (int*) malloc(queue -> capacity * sizeof(int));
	printf("\n Queue of capcaity %d is created.", capacity);
	
	return queue;

}


void enqueue(Queue* queue, int data)
{
//	Queue* queue =  queue;//(Queue*) malloc(sizeof(Queue));

	printf("\n Queue Rear is %d ", queue -> rear);
	++queue -> rear;
	++queue -> size;
	printf("\n Queue Rear is %d ", queue -> rear);	
	queue -> array[queue -> rear] = data;
	printf("\n %d is Enqueued to the Queue.",data);
	

}

int main()
{
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	
	createQueue(5);
	
	enqueue(queue, 23);
		
}

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
	queue -> capacity = capacity;
	queue -> array = (int*) malloc(queue -> capacity * sizeof(int));
	printf("\n Queue of capcaity %d is created.", queue -> capacity);
	
	return queue;

}

int isFull(Queue* queue)
{
	if (queue -> size == queue -> capacity)
	{
		printf("\n Queue is Full");
		return 1;
	}

	return 0;

}


int isEmpty(Queue* queue)
{	
	if (queue -> size == 0)
	{
		printf("\n Queue is Empty");
		return 1;
	}
	return 0;
	
}
void enqueue(Queue* queue, int data)
{

	if (isFull(queue) == 1)
		return;
	++queue -> rear;
	++queue -> size;
	queue -> array[queue -> rear] = data;
	printf("\n %d is Enqueued to the Queue.",data);
	
}


int dequeue(Queue* queue)
{
	int data;
	
	if (isEmpty(queue) == 1)
		return 0;
	data = queue ->array[queue -> front];
	++queue -> front;
	--queue -> size;

	return data;

}

int main()
{
	Queue* queue = createQueue(3);
	
	enqueue(queue, 23);
	enqueue(queue, 56);
	enqueue(queue, 78);
	enqueue(queue, 93);

	printf("\n Current size of Queue is %d\n", queue -> size);
		
	printf("\n The latest element dequeued is %d ", dequeue(queue));
	printf("\n The latest element dequeued is %d ", dequeue(queue));
	printf("\n The latest element dequeued is %d ", dequeue(queue));
	printf("\n The latest element dequeued is %d ", dequeue(queue));
	
	printf("\n Current size of Queue is %d\n", queue -> size);


}

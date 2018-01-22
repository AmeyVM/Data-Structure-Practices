#include<stdio.h>
#include<stdlib.h>


typedef struct 
{
	int data;
	unsigned int top;
	int* array;
}Stack;

/*This funtion creates the stack of given capacity.

@input :- int capacity (Stack capacity to be created)
@return :- Stack* (pointer to newly created stack)

*/

Stack* createStack(int capacity)
{
	Stack* stack = (Stack*) malloc(sizeof(Stack));       //Allocate memory to which 'stack' is pointing
	
	stack -> top = -1;                                   //Assign top = -1 as stack is being created here so no element will be there
	stack -> array = malloc(capacity * sizeof(Stack));   //Allocate memory for array of given capacity)
	printf("\n Stack of capacity %d has been created.", capacity);
	return stack;
}


int push(Stack* stack, int newdata)
{
	Stack* newElement = stack;
	(newElement -> top)++;
	newElement -> array[newElement -> top] = newdata;
//	(newElement -> top)++;
	printf("\n Current top of stack is %d", newElement -> top);
	printf("\n Last Element pushed onto stack is %d ", newElement -> array[newElement -> top]);
	return newElement -> top;
}

int pop(Stack* stack)
{
//	(stack -> top)--;
	return stack->array[stack->top--];	
}
int main()
{
	int capacity, top;
	Stack* stack;

	capacity = 5;
	stack = createStack(capacity);
	
	top = push(stack, 5);
//	top = push(stack, 12);
//	top = push(stack, 45);
//	top = push(stack, 249);

	if(top != -1)
	printf("\n First element has been pushed sucessfully onto stack");
	
	top = push(stack, 12);
        top = push(stack, 45);
        top = push(stack, 249);
	top = push(stack, 376);
	top = push(stack, 173);
	top = push(stack, 678); 

	printf("\n Current top of stack is %d and value last popped is %d", stack -> top, pop(stack));
	


	top = push(stack, 998);
	return 0;

}

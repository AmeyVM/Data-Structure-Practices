#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	char nodename;
	struct Node *next;
}Node;

void PrintList(Node* head)
{
	while(head -> next != NULL)
	 {
                printf("\n%d %c",head -> data, head -> nodename);
                head = head -> next;

         }
	printf("\n%d %c",head -> data, head -> nodename);	
}

Node* insertAtbeginning(Node *head, int data, char nodename)
{

	Node *bnode = (Node*) malloc(sizeof(Node));
	
	bnode -> data = data;
	bnode -> nodename = nodename;
	bnode -> next = head;
	
	return bnode;	
}

void insertAtpos(Node *head,Node *pos, int data, char nodename)
{
	Node *newnode = (Node*) malloc (sizeof(Node));
	
	while(head -> next == pos)
		head = head -> next;
	newnode -> data = data;
	newnode -> nodename = nodename;
	newnode -> next = head -> next;
	head -> next = newnode;
}


void insertAtEnd(Node *head, int data, char nodename)
{
	Node *enode = (Node*) malloc(sizeof(Node));
	
	while(head->next != NULL)
		head = head->next;
	enode->data = data;
	enode-> nodename = nodename;
	head ->next = enode;
	enode -> next =NULL;
}


int main()
{
	Node *head    = (struct Node *) malloc (sizeof(Node));
	Node *second  = (struct Node *) malloc (sizeof(Node));
	Node *third   = (struct Node *) malloc (sizeof(Node));
	Node *newNode = (struct Node *) malloc (sizeof(Node));


	head -> data = 1;
	head -> next = second;


	second -> data = 2;
	second -> nodename ='S';
	second -> next = third;

	third -> data = 3;
	third -> next = NULL;
	
	printf("\nPrinting original list");
	PrintList(head);

	newNode = insertAtbeginning(head, 5,'N');

	printf("\nPrinting New List with new node 'N' added at beginning:");
        PrintList(newNode);
 
	
	insertAtpos(head,second, 4, 'P');
         printf("\nPrinting New List with new node 'P' added after second node of original list:");
         PrintList(newNode);


	 insertAtEnd(head, 6, 'E');
         printf("\nPrinting New List with new node 'E' added at the end:");
	 PrintList(newNode);


	return 0;

	
}

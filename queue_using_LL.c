//queue using linked list

#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node
{
	int data;
	node* next;
};
node* front=NULL;
node* rear=NULL;


void enqueue(int data)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=NULL;
	if(rear==0)
		front = rear = temp;
	else
		rear=rear->next=temp;		
}

void dequeue()
{
	if(front==0)
		printf("\nQueue is empty.\n");
	else
	{
		node* d=front;
		front=front->next;
		free(d);
	}	
}
void display()
{
	node* p=front;
	while(p!=rear->next)
	{
		printf("%d  ",p->data);
		p=p->next;
	}
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	dequeue();
	printf("\n");
	display();
	dequeue();
	dequeue();
	dequeue();
}


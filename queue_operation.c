#include<stdio.h>
#include<stdlib.h>

int q[10];
int front=-1;
int rear=-1;
int size=10;

int isempty()
{
	
	if(rear<size && front == rear)
		return 1;
	else
		return 0;		
}

int isfull()
{
	if(rear == size-1)
		return 1;
	else 
		return 0;	
}

void enqueue(int data)
{
	if(!isfull())
		q[++rear]=data;
	else
	{
		printf("\nQueue is full");
	}	
}

int dequeue()
{
	if(isempty()==0)
		return q[++front];
	else
	{
		printf("\nQueue is empty");
		return -1;
	}	
}
void display ()
{
	int i;
	for (i=front+1;i<=rear;i++)
	{
		printf("%d  ",q[i]);
	}
}
int peek()
{
	return q[front+1];
}

int main()
{
	enqueue(6);
	enqueue(76);
	
	display();
	printf("delete num = %d",dequeue(),dequeue(),dequeue());
	
	display();
	

}

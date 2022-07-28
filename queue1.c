#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int front;
	int rear;
	int *ptr;
};

void create(struct queue *p)
{
	p->ptr=(int*)malloc(p->size*sizeof(int));
	p->front=p->rear=-1;
}


void enqueue(struct queue* q,int data)
{
	if(q->rear==q->size-1)
		printf("\nQueue is full.");
	else
	{
		q->rear++;
		q->ptr[q->rear]=data;
	}		
}

int dequeue (struct queue *q)
{
	if(q->front==q->rear)
		printf("\nQueue is empty");
	else
	{
		q->front++;
		return q->ptr[q->front];
	}	
}
void display(struct queue q)
{
	int i;
	for (i=q.front+1;i<=q.rear;i++)
		printf("%d  ",q.ptr[i]);
		
	printf("\n");	
}


int main()
{
	
	struct queue Q;
	printf("Enter the size of queue : ");
	scanf("%d",&Q.size);
	create(&Q);
	
	enqueue(&Q,45);
	enqueue(&Q,4);
	display(Q);
	printf("\ndeleted element : %d",dequeue(&Q));
	
	return 0;
}

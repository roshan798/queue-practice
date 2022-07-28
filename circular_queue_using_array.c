#include<stdio.h>
#include<stdlib.h>

 
struct queue 
{
	int front;
	int rear;
	int size;
	int *ptr;
};

void create(struct queue* q)
{
	q->ptr=(int*)malloc((++q->size) * sizeof(int)); ///+1 size for the  space b/t end and star of queue
	q->front=q->rear=0;
}

int isempttfy(struct queue q)
{
	if(q.front==q.rear)
		return 1;
	else
		return 0;	
}

int isfull(struct queue q)
{
	if(q.front==(q.rear+1)%q.size)
		return 1;
	else 
		return 0;	
}
void enqueue(struct queue* q,int data)
{
	if(isfull(*q))
		printf("\nQueue is full\n");
	else
	{
		q->rear=(q->rear+1)%q->size;
		q->ptr[q->rear]=data;
	}	
}

int dequeue (struct queue* q)
{
	if(isempty(*q))
		printf("\nQueue is empty\n");
	else
	{
		q->front=(q->front+1)%q->size;
		return q->ptr[q->front];
	}	
}

void display(struct queue q)
{
	if(!isempty(q)){
	int i=(q.front+1)%q.size;
	for (;i<=q.rear;i++)
		printf("%d  ",q.ptr[i]);
		
	printf("\n");	
	}
}
int main()
{
	struct queue q;
	
	printf("Enter the size of queue : ");
	scanf("%d",&q.size);
	create(&q);
    int num,element;
	printf("\nEnter the number of elemnts you want to insert(< %d) in the queue : ",q.size);
	scanf("%d",&num);
	printf("Enter %d numbers :",num);
	for( ; num>0;num--)
	{
		scanf("%d",&element);
		enqueue(&q,element);
	}
	printf("\n\nEntered elements in the queue : ");
	display(q);	
	
	printf("\n\nEnter the number of elemnts(<%d) you want to delete in the queue : ",q.size);
	scanf("%d",&num);
	for (;num>0;num--)
		dequeue(&q);
	
	printf("\n After deletion \n queue elements :");
	display(q);
	
	printf("\nEnter the number of elemnts you want to insert in the queue : ");
	scanf("%d",&num);
	printf("Enter %d numbers :",num);
	for( ; num>0;num--)
	{
		scanf("%d",&element);
		enqueue(&q,element);
	}
	printf("\n\nEntered elements in the queue : ");
	display(q);	
	return 0;
}

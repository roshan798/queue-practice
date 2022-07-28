#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<stdio.h>
typedef struct stack
{
    
    int* arr;
    int top;
    int size;
}stack;
bool isfull(stack* s)
{
    if (s->top== (s->size-1))
        return 1;
    return 0;
}

bool isempty(stack* s)
{
    if (s->top== -1)
        return 1;
    return 0;
}

void push(stack* s,int data)
{
    if (isfull(s))
        return;
    else 
        s->arr[++(s->top)]=data;
}
int pop(stack* s)
{
    if (isempty(s))
        return -1;
    else 
        return s->arr[s->top--];
}
void enqueue(int data,stack* s1,stack* s2)

{
    if (isfull(s1)) 
        while (!isempty(s1)) 
            push(s2, pop(s1));
    else 
        push(s1, data);
    
}
void dequeue(stack* s1,stack* s2)
{
    if (isempty(s2)) {
        while (!isempty(s1)) 
            push(s2, pop(s1));
    }
    pop(s2);
}
int peek(stack* s1,stack* s2)
{
    if (isempty(s2)) {
        while (!isempty(s1)) 
            push(s2, pop(s1));
    }
    return s2->arr[s2->top];
}
void display(stack* ptr)
{
	int n=ptr->top;
	
	for(;n>=0;n--)
		printf("%d  ",ptr->arr[n]);
}

int main() {
    
    stack s1,s2;
    s1.size =s2.size=1e5;
    int queries_count,q,x;
    s1.arr=(int*)malloc(s1.size*sizeof(int));
    s2.arr=(int*)malloc(s2.size*sizeof(int));
    s1.top=s2.top=-1;
    printf("Enter No of q's : ");
    scanf("%d",&queries_count);
    int data;
    for (int i=0; i<queries_count; i++) {
    	printf (" Select one option : \n\t 1. Enqueue\n\t 2. Dequeue\n\t 3. Front element\n");
        scanf("%d",&q);
        switch (q) {
            case 1: 
            printf("\nEnter DATA : ");
                scanf("%d",&data);
                enqueue(data,&s1,&s2);
                break;
            case 2:
                dequeue(&s1,&s2);
                break;
            case 3:
            	
                printf("Front Elemenet  : - %d\n",peek(&s1,&s2));
                break;
        } 
        printf("\n%d  --> ",i);
		display(&s1);  
    }
    return 0;
}

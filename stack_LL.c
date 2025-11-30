#include<stdio.h>
#include<stdlib.h>

//defining a node
struct node
{
	int info;
	struct node *next;
};

void push_stack(int);
void display_stack();
int pop_stack();

struct node *head=NULL;	//global variable
struct node *top=NULL;		

void main()
{	
	int n,i,item;
	
	//push into stack
	for(i=1;i<=10;i++)
	{
		printf("enter no.: ");
		scanf("%d",&n);
		
		push_stack(n);
	}	
	
	display_stack();	//display the list
	
	printf("\n");
	
	item=pop_stack();	//pop operation
	
	printf("the popped item is : %d",item);
	
	printf("\n");
	
	display_stack();	//display the list
}

void push_stack(int data)
{
	struct node *s;
	
	//creating a node
	s=malloc(sizeof(struct node));
	s->info=data;
	s->next=NULL;
	
	//checking if the stack is empty
	if(top==NULL)
	{
		head=s;	//assign head and top to the start node
		top=s;			
	}		
	else
	{
		//assign top to the end node
		top->next=s;		
		top=s;
	}
	
	fflush(stdin);	//clean the buffer
}

void display_stack()
{
	struct node *s;
	
	s=head;	//assign a temporary pointer variable to the start node for traversing
	
	//traversing the list until there is no node left
	while(s!=NULL)
	{
		printf("%d->",s->info);
		s=s->next;
	}
	printf("X");
}

int pop_stack()
{
	struct node *s;
	int item;
	
	if(top==NULL)
	{
		printf("stack is empty.....");
		exit(1);
	}
	
	s=head;	//assign a temporary pointer variable to the start node for traversing
		
	//traversing the list until the second last node is reached
	while(s->next->next!=NULL)
	{
		s=s->next;
	}
	
	//delete the last node (pop operation)
	
	item=top->info;	//store top element to item
	
	top=s;	//assign top to second last node
	
	s=s->next;	//traverse to last node
	
	free(s);	//free the memory location of the last node
	
	top->next=NULL;	//make top the last node	
	
	return (item);	//return item
}

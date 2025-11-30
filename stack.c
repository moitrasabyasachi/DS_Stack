#include<stdio.h>
#include<stdlib.h>
#define MAX 5


int s[MAX], top = -1;


void push(int item)
{
	if(top == (MAX-1))
	{
		printf("Overflow\n");		
	}
	else
	{
		top++;
		s[top] = item;
		printf("item Pushed\n");
	}	
}

int pop()
{
	int item;
	
	if(top == -1)
	{
		printf("Underflow\n");
		exit(1);
	}
	
	item = s[top];
	top--;
	
	return item;		
}

void display()
{
	int i;

	for (i = 0; i <= top; i++)
	{
		printf("%d ", s[i]);
	}
	
	printf("\n");
}


void main()
{
	int ch, item, i;

	while (1)
	{
		printf("---------------------------\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("enter choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
				printf("enter item: ");
				scanf("%d", &item);
				
				push(item);

				break;

			case 2:
				item = pop();
	
				printf("Popped item = %d\n", item);

				break;
			
			case 3:
				display();

				break;

			case 4:
				exit(0);
			
			default:
				printf("Wrong choice\n");
				break;
		}
	}
}

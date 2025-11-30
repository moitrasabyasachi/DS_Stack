#include<stdio.h>
#include<string.h>
#define MAX 100

int s[MAX]; 
int top = -1;

int rightTrim(char str[], int len)
{     
     int k, idx;
     char ch;

     for (k = len-1; k >= 0; k--)
	{
		ch = str[k];		

		if (ch != ' ')
		{
			idx = k;			
			break;
		}		
	}
     
     return idx;
}

void leftTrim(char str[], int len)
{     
     int k, idx, i;
     char ch;

     for (k = 0; k < len; k++)
	{
		ch = str[k];

		if (ch != ' ')
		{
			idx = k;			
			break;
		}		
	}

     for (k = 0, i = idx; i < len; i++, k++)
	{
		str[k] = str[i];
	}
}

void push(int item)
{
	top++;
     s[top] = item;     	
}

int pop()
{
	int item;	
	
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
     char expr_pos[MAX], wrd[MAX];
     int len, i, j = 0;
     
     printf("enter postfix expression: ");
     gets(expr_pos);

     len = strlen(expr_pos);

     //right trim
     int idx = rightTrim(expr_pos, len);
     expr_pos[idx+1] = ' ';   //add an extra white space at the end
     expr_pos[idx+2] = '\0';

     //left trim
     leftTrim(expr_pos, len);    
    
     //scan from left to right
     for (i = 0; expr_pos[i] != '\0'; i++)
     {
          //operand / operator extraction
          if (expr_pos[i] == ' ' && expr_pos[i+1] != ' ')
          {
               wrd[j] = '\0';          
               idx = rightTrim(wrd, strlen(wrd));
               wrd[idx+1] = '\0';
               // printf("\n%d", atoi(wrd));
               // printf("\n%d", strlen(wrd));
               if (strcmp(wrd, "+") == 0 || strcmp(wrd, "-") == 0 || strcmp(wrd, "*") == 0 || strcmp(wrd, "/") == 0 || strcmp(wrd, "%") == 0)
               {
                    //operator
                    int n2 = pop();
                    int n1 = pop();
                    int res;

                    switch (wrd[0])
                    {
                         case '+':
                              res = n1 + n2;
                              push(res);
                              break;               
                         case '-':
                              res = n1 - n2;
                              push(res);
                              break;
                         case '*':
                              res = n1 * n2;
                              push(res);
                              break;
                         case '/':
                              res = n1 / n2;
                              push(res);
                              break;
                         case '%':
                              res = n1 % n2;
                              push(res);
                              break;
                         default:
                              break;
                    }
               }
               else
               {
                    push(atoi(wrd));    //operand
               }                    

               j = 0;
          }
          else
          {
               wrd[j] = expr_pos[i];
               j++;
          }        
     }

     display();     //display result
}
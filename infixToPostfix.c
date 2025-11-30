#include<stdio.h>
#include<string.h>
#define MAX 100

char expr_pos[MAX], op[MAX]; 
int top = -1, top2 = -1;

void push(char item)
{
	//push operand / operator to expr_pos
    top++;
    expr_pos[top] = item;    
}

void pop()
{
    //pop operator from op and push it to expr_pos until '('    
    char ch;

    while (op[top2] != '(')
    {
        ch = op[top2];
        push(ch);
        top2--;
    }

    top2--;    
}

int get_op_precedence(char item)
{
    //get operator precedence
    switch (item)
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;        
    }
}

char pop2()
{
    //pop operator from op
    char ch;

    ch = op[top2];
    top2--;

    return ch;
}

void push2(char item)
{    
    int pr, pr2;
    char ch;

    if (item == '(')
    {
        //push ( to op
        top2++;
        op[top2] = item;
    }
    else
    {
        pr = get_op_precedence(item);  //get current operator precedence
        pr2 = get_op_precedence(op[top2]);  //get top operator precedence

        if (pr > pr2)
        {
            //push operator to op if pr > pr2
            top2++;
            op[top2] = item;
        } 
        else
        {
            //pop operator from op until pr <= pr2 and push them to expr_pos
            ch = pop2();
            push(ch);
            
            push2(item);        
        }
    }                   	
}

void main()
{
    char expr_inf[MAX], ch;
    int len, i, j;

    printf("enter infix expression: ");
    gets(expr_inf);

    len = strlen(expr_inf);

    printf("Scanned\tStack\tExpression\n");
    
    //scan from left to right
    for (i = 0; i < len; i++)
    {
        ch = expr_inf[i];
        
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            push(ch);   //push operand to expr_pos
        }
        else
        {
            if (ch == ')')
            {
                pop();  //pop operator from op and push it to expr_pos until '('
            }            
            else
            {
                push2(ch);  //push operator to op
            }            
        }

        //printing steps
        printf("%c\t", ch);

        for (j = 0; j <= top2; j++)
        {
            printf("%c", op[j]);
        }
        printf("\t");
        
        for (j = 0; j <= top; j++)
        {
            printf("%c", expr_pos[j]);
        }
        printf("\t");

        printf("\n");
    }

    top++;
    expr_pos[top] = '\0';

    printf("\nPOSTFIX EXPRESSION: %s", expr_pos);    
}
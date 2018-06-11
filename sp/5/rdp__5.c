#include<stdio.h>
#include<string.h>
#include<ctype.h>

int i, flag;
char input[20];

void E();
void T();
void E_();
void T_();
void F();

void main() 
{
	i=0;
	flag=1;
	printf("Enter String : ");
	scanf("%s", input);
	E();
	if(flag && i==strlen(input))
	{
		printf("String Accepted!\n");
	} 
	else 
	{
		printf("Error\n");
	}
}

void E() 
{
	T();
	E_();
}

void E_() 
{
	if(input[i]=='+' || input[i]=='-')
	{
		i++;
		T();
		E_();
	}
}

void T() 
{
	F();
	T_();
}

void T_() {
	if(input[i]=='*' || input[i]=='/')
	{
		i++;
		F();
		T_();
	}
}

void F() 
{
	if((input[i]>='a' && input[i]<='z') || isalnum(input[i]))
     	{
		i++;
	}
	else
        	if(input[i]=='(')
           	{
			i++;
		  	E();
		   	if(input[i]==')')
              		{
				i++;
		   	}
             		else
             		{
				flag=0;
		  	}
	    	}
        	else
          	{
			flag=0;
	    	}
}

      /*OUTPUT
gcc rdp_5.c
./a.out

      Enter String : (c+b)*a
      String Accepted!

      Enter String : (a+b*c
      Error*/

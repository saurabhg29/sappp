#include<stdio.h>
#include<string.h>


typedef struct symtab
{

char symbol[10];
int address;
}symtab;


typedef struct pooltable
{

int index;
int noofl;

}pooltable;

typedef struct ltable
{

char literal[10];
int address1;

}ltable;



symtab st[4]={{"LOOP",200},
{"A",206},
{"B",210},
{"C",211}};

pooltable pt[2]=
{
{1,2},
{3,0}
};

ltable lt[2]={
{"1",204},
{"2",209}
};

int main()
{
char tok1[40],tok2[40],tok3[40],tok4[40],str[40],temp[10];
int i,k,dup,n;
FILE *fp1,*fp2;
fp1=fopen("a.txt","r");
fp2=fopen("pass2.txt","w");
while(fgets(str,80,fp1))
{

n=sscanf(str,"%s%s%s%s",tok1,tok2,tok3,tok4);
	switch(n)
	{
	case 4:
	fprintf(fp2,"%s",tok1);
	
	for(i=4,k=0;tok2[i]!=')';i++,k++)
	{
	temp[k]=tok2[i];
	
	}
	temp[k]='\0';
	fprintf(fp2," %d",atoi(temp));
	
	fprintf(fp2," %s",tok3);
	
	
	for(i=3,k=0;tok4[i]!=')';i++,k++)
		{
		temp[k]=tok4[i];
	
	
		}
		temp[k]='\0';
		dup=atoi(temp);
	printf("**%d**\n",dup );
	if(tok4[1]=='s')
	{
	
		
		dup=st[dup].address;
		printf("%d\n",dup );
	
	}
	else
	{
	
		printf("--LB %d\n",dup );
		dup=lt[dup-1].address1;
		printf("--LA%d\n",dup);
	
	}

	fprintf(fp2," %d\n",dup);
	break;


	/************************************************/
	case 3:
	fprintf(fp2,"%s",tok1);
	
	if(tok2[4]=='2')
	{
	
	fprintf(fp2," 00\n");
	}
	else
	{
	
	fprintf(fp2," 00");
	
	for(i=3,k=0;tok3[i]!=')';i++,k++)
	{
	
		temp[k]=tok3[i];
	
	
	
	
	}
	temp[k]='\0';
	dup=atoi(temp);
	
	fprintf(fp2," %d\n",dup);
	
	
	
	}
	





	}//switch
	



}//while

fclose(fp1);
fclose(fp2);


return 0;
}

/*



*/

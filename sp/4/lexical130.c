#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare(char abc[30]);
int compare1(char abc);
int compare2(char abc[30]);
int isnum(char tok[30]);

typedef struct literal
{
	int index;
	char value[100];
	char name[40];
}lite;

lite lt[1000];

typedef struct identifier
{
	int index1;
	char identi[40];
	char name[40];	
}ident;

ident idt[1000];

typedef struct terminal
{
	int index2;
	char term[50];
	char name[50];
}term;

term tm[1000];

typedef struct operator1
{
	char op[20];
}operate;
	
operate opr[22]={"+","-","*","/","++","--",">","<",">=",
"==","<=","&","|","&&",
"!","(",")","{","}",
",",";","="};

typedef struct uniform
{
	int index3;
	int tabindex;
	char sym[50];
	char tabname[50];
}unif;

unif ust[3000];

typedef struct keyword1
{
	char key[50];
}keyw;

typedef struct defidentifier
{
	char key1[50];
}defident;



keyw kw[32]={"auto","break","case","char","continue","do","default","const",
"double","else","enum","extern","for","if","goto","float","int",
"long","register","return","signed","static","sizeof","short",
"struct","switch","typedef","union","void","while","volatile","unsigned"};

int tt=0,it=0,li=0,usi=0;

int main()
{
	int i,n,j,m,k,s,f,l;
	f=1;
	
	FILE *fp1,*fp2;
	fp1=fopen("1.c","r");
	char str[80],str1[80],str2[80],str3[80],temp[2];
	while(fgets(str,80,fp1))
	{
		
	
		for(i=0,j=0;j<strlen(str);i++,j++)
	    {
	    	n=5,l=5,m=5;
	    	while(str[j]==' ' || m==2 ||   str[j]=='	')
	    	{
	    	//if(str[j]==' ' || m==2 || str[j]=='	')
	    		j++;
	    	}
    		str1[i]=str[j];
    		s=i+1;
    		str1[s]='\0';
    		n=compare(str1);
		if(str[j+1]!='\0')
    		m=compare1(str[j+1]);
    		
    		if(n==0 && m==2)
    		{
    			//char temp[2];
    			temp[0]=str[j+1];
    			temp[1]='\0';
    			
    			s=isnum(str1);
    			if(s==-1)
    			{
    				
				l=compare2(str1);
    				if(str1[0]=='"' && str[j]=='"')
    				{
    					l=compare2(str1);
					if(l!=3)
    					{
    				//	int val;
    				//	val=atoi(str1);
   					lt[li].index=li;
    					strcpy(lt[li].value,str1);
    					strcpy(lt[li].name,"LIT");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
					ust[usi].index3=usi;
					ust[usi].tabindex=li;
					strcpy(ust[usi].sym,str1);
    					strcpy(ust[usi].tabname,"LIT");
					
					usi++;
					li++;
					}
    				}
    				else
    				if(l!=2)
    				{
    					idt[it].index1=it;
    					strcpy(idt[it].identi,str1);
    					strcpy(idt[it].name,"IDN");
    					//printf("\n%d,%s,%s",idt[it].index1,idt[it].identi,idt[it].name);
    					ust[usi].index3=usi;
					ust[usi].tabindex=it;
					strcpy(ust[usi].sym,str1);
    					strcpy(ust[usi].tabname,"IDN");
    					
    					usi++;
    					it++;
    				}
    				/*
    				l=compare2(temp);
    				if(l!=1)
    				{
   					tm[tt].index2=tt;
    					strcpy(tm[tt].term,temp);
    					strcpy(tm[tt].name,"TRM");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
					ust[usi].index3=usi;
				 	ust[usi].tabindex=tt;
					strcpy(ust[usi].sym,temp);
    					strcpy(ust[usi].tabname,"TRM");
					
					usi++;
					tt++;	
				}*/
    				i=-1;
			}
			else
			if(s==1)
			{
				l=compare2(str1);
				if(l!=3)
    				{
    					int val;
    					//val=atoi(str1);
   					lt[li].index=li;
    					strcpy(lt[li].value,str1);
    					strcpy(lt[li].name,"LIT");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
					ust[usi].index3=usi;
					ust[usi].tabindex=li;
					strcpy(ust[usi].sym,str1);
    					strcpy(ust[usi].tabname,"LIT");
					
					usi++;
					li++;
				}
				i=-1;	
			}
    		}
    		if(n==1)
    		{
    			l=compare2(str1);
    			if(l!=1)
    			{
    				tm[tt].index2=tt;
    				strcpy(tm[tt].term,str1);
    				strcpy(tm[tt].name,"KW");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
    				ust[usi].index3=usi;
				ust[usi].tabindex=tt;
				strcpy(ust[usi].sym,str1);
    				strcpy(ust[usi].tabname,"KW");
    				
    				usi++;
    				tt++;
    			}
    			i=-1;
    			
    			//printf("%c",str1[2]);
    		}	
    		if(n==2)
    		{
    			if(m==2)
    			{
    				temp[0]=str[j+1];
    				temp[1]='\0';
    				strcpy(str3,str1);
    				strcat(str3,temp);
    				l=compare2(str3);
    				m=compare(str3);
    				//printf("\n%s\n",str1);
    				if(l!=1 && m==2)
    				{
    					tm[tt].index2=tt;
    					strcpy(tm[tt].term,str3);
    					strcpy(tm[tt].name,"TRM");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
    					ust[usi].index3=usi;
					ust[usi].tabindex=tt;
					strcpy(ust[usi].sym,str3);
    					strcpy(ust[usi].tabname,"TRM");
    					
    					usi++;
    					tt++;
    					j++;
    				}
    				else
    				{
    					l=compare2(str1);
    					if(l!=1)
    					{
    						tm[tt].index2=tt;
    						strcpy(tm[tt].term,str1);
    						strcpy(tm[tt].name,"TRM");
    					//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
    						ust[usi].index3=usi;
						ust[usi].tabindex=tt;
						strcpy(ust[usi].sym,str1);
    						strcpy(ust[usi].tabname,"TRM");
    						
    						usi++;
    						tt++;
    					}	
    				}	
    				i=-1;
    			}
    			else
    			{
    				l=compare2(str1);
    				if(l!=1)
    				{
    					tm[tt].index2=tt;
    					strcpy(tm[tt].term,str1);
    					strcpy(tm[tt].name,"TRM");
    				//printf("\n%d,%s,%s",tm[tt].index2,tm[tt].term,tm[tt].name);
    					ust[usi].index3=usi;
					ust[usi].tabindex=tt;
					strcpy(ust[usi].sym,str1);
    					strcpy(ust[usi].tabname,"TRM");
    					
    					usi++;
    					tt++;
    				}
    				i=-1;
    			}
    		}
    	                      	        
	    }
	   
	     
	}	
	printf("\nTerminal Table");
	printf("\nIndex\tSymbol\tType");
	for(i=0;i<tt;i++)
	{
		printf("\n%d\t%s\t%s",tm[i].index2,tm[i].term,tm[i].name);
	}
	printf("\n\n");
	printf("\nIdentifier Table");
	printf("\nIndex\tSymbol\tType");
	for(i=0;i<it;i++)
	{
		printf("\n%d\t%s\t%s",idt[i].index1,idt[i].identi,idt[i].name);
	}
	printf("\n\n");
	
	printf("\nLiteral Table");
	printf("\nIndex\tValue\tType");
	for(i=0;i<li;i++)
	{
		printf("\n%d\t%s\t%s",lt[i].index,lt[i].value,lt[i].name);
	}
	printf("\n\n");
	
	printf("\nUniversal Symbol Table");
	printf("\nIndex\tR.Index\tSymbol\tType");
	for(i=0;i<usi;i++)
	{
		printf("\n%d\t%d\t%s\t%s",ust[i].index3,ust[i].tabindex,ust[i].sym,ust[i].tabname);
	}
	printf("\n\n");
	 
	// printf("\n%d,%s,%s",idt[0].index1,idt[0].identi,idt[0].name);
	return 0;
}

int compare(char abc[30])
{
	int i;
	for(i=0;i<32;i++)
	{
		if(strcmp(abc,kw[i].key)==0)
		return 1;
	}
	for(i=0;i<22;i++)
	{
		if(strcmp(abc,opr[i].op)==0)
		return 2;
	}
	return 0;
}

int compare1(char abc)
{
	int i;
	char abc1[30];
	abc1[0]=abc;
	abc1[1]='\0';
	for(i=0;i<22;i++)
	{
		if(strcmp(abc1,opr[i].op)==0)
		return 2;
	}
	return 0;
}

int compare2(char abc[30])
{
	int i,j;
	for(i=0;i<tt;i++)
	{
		if(strcmp(abc,tm[i].term)==0)
		return 1;
	}
	for(i=0;i<it;i++)
	{
		if(strcmp(abc,idt[i].identi)==0)
		return 2;
	}
	//j=atoi(abc);
	for(i=0;i<li;i++)
	{
		//j=atoi(abc);
		if(strcmp(lt[i].value,abc)==0)
		return 3;
	}
	return 0;
	
}

int isnum(char tok[30])
{
	int i;
	for(i=0;i<strlen(tok);i++)
	{
		if(!isdigit(tok[i]))
			return -1;
	}
	return 1;
}


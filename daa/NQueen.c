

#include<stdio.h>
#include<math.h>
int NQueen(int r ,int n);
int x[20],count;

int NQueen(int r,int n)
{
	int c,i;
    for(c=1;c<=n;c++)
    {
    	   if(plac e(r,c))
    	   {
    		   x[r]=c;
    		   if(r==n)
    		   {
    			   print(n);
    		   }
    		   else
    		   {
    			   NQueen(r+1,n);
    		   }
    	   }
   }
    return 0;
}
int place(int  r,int c)
{  int i;
	for(i=1;i<=r-1;i++)
	{
		if(x[i]==c)
		{
			return 0;
		}
		else
		{
			if(abs(x[i]-c)==abs(i-r))
			{
			return 0;
			}
		}
	}
	return 1;
}
int print(int n)
{
 int i,j;
 printf("\n\nSolution %d \n\n",++count);
 for(i=1;i<=n;i++)
 {
	 printf("\t%d",i);
 }
 for(i=1;i<=n;i++)
 {
	 printf("\n%d",i);
			 for(j=1;j<=n;j++)
			 {
				 if(x[i]==j)
					 printf("\t Q");
				 else
					 printf("\t -");
			 }

 }
 return 0;
}
int main()
{
	int i,j,n,r;
	printf("\n ****** N-Queen Solution *****\n");
	printf("\n Enter the Queen:-\n");
	scanf("%d",&n);
	NQueen(1,n);
	return 0;
}
/* OUTPUT:-
 

 ****** N-Queen Solution *****

 Enter the Queen:-
4


Solution 1

	1	2	3	4
1	 -	 Q	 -	 -
2	 -	 -	 -	 Q
3	 Q	 -	 -	 -
4	 -	 -	 Q	 -

Solution 2

	1	2	3	4
1	 -	 -	 Q	 -
2	 Q	 -	 -	 -
3	 -	 -	 -	 Q
4	 -	 Q	 -	 -
 */

#include<stdio.h>
void MaxMin(int a[20], int i, int j, int *max, int *min);
void main()
{
	int a[20], max=0,min=0,n,i;
	printf("\n enter number of elements");
	scanf("%d",&n);
	if(n!=0)
	{
	printf("\n Enter values:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	
	}
	 MaxMin(a, 0, n-1, &max, &min);
	printf("\n max = %d, min= %d", max,min);

	}
	else
		printf("\n no element in array");
}

void MaxMin(int a[20], int i, int j, int *max, int *min)
{
  int mid, max1=0,max2=0,min1=0,min2=0;
     if (i==j)   // for single element
    {
	*max = a[i];
	*min = a[i];
	return;
    }	

     else if (i==j-1) //if 2 elements in array
          {
                if (a[i] < a[j])
		{ *max = a[j]; *min = a[i]; return; }
                else { *max = a[i]; *min = a[j]; return;}
          }
     else
     {
          
           mid = ( i + j )/2;
          
           MaxMin(a,i, mid, &max1, &min1 );
           MaxMin(a,mid+1, j, &max2, &min2 );
	          
	   if (min1 > min2) 
		*min = min2; 
	  else 	*min = min1;


           if (max1 < max2)
		  *max = max2;
	   else
		 *max = max1; 
		
			

	  
     }
}
/*OUTPUT
 enter number of elements7

 Enter values:12
67
45
34
23
89
66

 max = 89, min= 12    */

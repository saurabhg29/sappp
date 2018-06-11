#include<stdio.h>
typedef struct file1
{ int index, size;
}f;

void merge_sort(f A[30],int n);
void merge(f A[30], int l1, int h1, int h2);
void greedy(int t, int n, f files[20], f tape[5][20], int k[5]);
void search(int t, int n, f files[20], f tape[5][20], int k[5], int key);
int main()
{
   f files[20], tape[5][20];
   int k[5]={0};
   int t, n,key=0;
   int i=0,j=0;
   printf("\n enter number of tapes");
   scanf("%d",&t);
   printf("\n enter number of files");
   scanf("%d",&n);
   printf("\n enter file number and respective size");
   for(i=0;i< n;i++)
	scanf("%d%d",&files[i].index, &files[i].size);

    merge_sort(files, n);
	printf("\n After sort:");
	printf("\nFile No\t File size\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d\t\t%d ", files[i].index,files[i].size);
	}

	greedy(t,n,files,tape, k);

	printf("\nTape No \t Total files \t Files on tapes  with size: (index,size)");
   for(i=0; i<t;i++)
   {
	printf("\n\n %d  \t \t%d\t\t ", i+1, k[i]);
	for(j=0;j< k[i];j++)
	{
		printf(" (%d , %d)\t",tape[i][j].index,tape[i][j].size);

	}
   }

	printf("\n enter the file no. you want to search:");
	scanf("%d",&key);
	search(t,n,files,tape, k,key);
return 0;
}
void greedy(int t, int n, f files[20], f tape[5][20], int k[5])
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		tape[j][k[j]].index = files[i].index;
		tape[j][k[j]].size =  files[i].size;
		k[j]++;
		j=(j+1)%t;
	}


}


void search(int t, int n, f files[20], f tape[5][20], int k[5], int key)
{
	int i,j;
printf("\n in search");
for(i=0; i<t;i++)
   {
	for(j=0;j< k[i];j++)
	{
		if(key == tape[i][j].index)
		{	printf("\n File %d is present on tape %d",tape[i][j].index, i+1);
			return;
		}

	}
   }
	printf("\n file not found");
}

void merge_sort(f A[30],int n)
{
	f temp[30];
	int l1, h1, l2, h2,size,i;
	for(size=1;size<n;size=size*2)
	{
		l1=0;
		
		while(l1+size<n)
		{
			h1 = l1 + size -1;
			l2 = h1 + 1;
			h2 = l2 + size -1;
			if(h2>=n)
			{
				h2 = n-1;
			}
			merge(A, l1, h1, h2);	//merging of 2 sorted arrays function


			l1 = h2 +1;
		}//while
	}
}//merge sort

void merge(f A[30], int l1, int h1, int h2)
{       f temp[30];
	int i=l1;
	int j=h1+1;
	int k=0;

	while(i<=h1 && j<=h2) //Till end of Ist List or IInd List
	{
		if(A[i].size <=A[j].size)
		{
			temp[k].index = A[i].index;
			temp[k].size = A[i].size;
			k++;
			i++;
		}
		else
		{
			temp[k].index = A[j].index;
			temp[k].size = A[j].size;
			k++;
			j++;
		}
	}//end of while

	while(i<=h1)   // if end of IInd list ,copy Ist List
	{
		temp[k].index = A[i].index;
		temp[k].size = A[i].size;
		k++;
		i++;
	}

	while(j<=h2) // if end of Ist list ,copy IInd List
	{
		temp[k].index = A[j].index;
		temp[k].size = A[j].size;
		k++;
		j++;
      }

		for(i=l1,k=0;i<=h2;i++,k++)//copt temp elements                        								elemnts
		{
			A[i].index=temp[k].index;
			A[i].size=temp[k].size;

		}

}

/*OUTPUT
 enter number of tapes3

 enter number of files4

 enter file number and respective size1
23
2
12
3
89
4
30

 After sort:
File No  File size

 2              12
 1              23
 4              30
 3              89
Tape No          Total files     Files on tapes  with size: (index,size)

 1              2                 (2 , 12)       (3 , 89)

 2              1                 (1 , 23)

 3              1                 (4 , 30)
 enter the file no. you want to search:3

 in search
 File 3 is present on tape 1   */


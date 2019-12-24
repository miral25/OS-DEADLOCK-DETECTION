#include<stdio.h>
int max[100][100];
int alloc[100][100];
int avail[100];
int n,r;
void input();
void display();
void calculate();
int main()
{
	printf("\nDEADLOCK DETECTION ALGORITHM\n");
	input();
	display();
	calculate();
	return 0;
}
void input()
{
	int i,j;
	printf("\nEnter the no of Processes: ");
	scanf("%d",&n);
	printf("Enter the no of resource instances: ");
	scanf("%d",&r);
	printf("Enter the Max Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the Allocation Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the available Resources: \n");
	for(j=0;j<r;j++)
	{
		scanf("%d",&avail[j]);
	}
}
void display()
{
	int i,j;
	printf("Process\t\tMax\t\tAllocation\t\tAvailable");
	for(i=0;i<n;i++)
	{
		printf("\nP%d\t\t\t",i+1);
		for(j=0;j<r;j++)
		{
			printf("%d ",max[i][j]); 
		}
		printf("\t\t");
		for(j=0;j<r;j++)
		{
			printf("%d ",alloc[i][j]);
		}	
		printf("\t\t");
		if(i==0)
		{
			for(j=0;j<r;j++)
			{	
				printf("%d ",avail[j]);
			}	
		}
	}
}
void calculate()
{
	int finish[100],dead[100],need[100][100];
	int flag=1,i,j,k;
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	while(flag==1)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			int c=0;
			for(j=0;j<r;j++)
			{
				if((finish[i]==0)&&(need[i][j]<=avail[j]))
				{
					c++;
					if(c==r)
					{
						for(k=0;k<r;k++)
						{
							avail[k]= avail[k] + alloc[i][j];
							finish[i]=1;
							flag=1;
						}
						if(finish[i]==1)
						{
							i=n;
						}
					}
				}
			}
		}
    }
	j=0;
	flag=0;
	for(i=0;i<n;i++)
	{
		if(finish[i]==0)
		{
			dead[j]=i;
			j++;
			flag=1;
		}
	}
	if(flag==1)
	{
		printf("\n\nSystem is in Deadlock and the Deadlock process are:\n");
		for(i=0;i<n;i++)
		{
			printf("P%d\t",dead[i]);
		}
	}
	else
	{
		printf("\n\nNo Deadlock Detected");
	}  
}
/*
no deadlock
max
5 6 3
8 5 6
4 8 2
7 4 3
4 3 3
alloc
2 1 0
3 2 3
3 0 2
3 2 0
1 0 1
total
15 8 8
*/
/*
deadlock
max
3 6 8
4 3 3
3 4 4
alloc
3 3 3
2 0 3
1 2 4
total
1 2 0
*/

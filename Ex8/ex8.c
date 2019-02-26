#include<stdio.h>
#include<stdlib.h>
int main()
{
int c,i,k=-1,j,n,m,need[10][10],alloc[10][10],max[10][10],av[10],a[10],flag=0,l,flag2,an[10],count=0,ne[10][10],p;
char r[10];
printf("\nBanker's Algorithm:\n\n1. Read Data\n2. Print Data\n3. Safety Sequence\n4. Exit");
while(1)
{
	printf("\nEnter option: ");
scanf("%d",&c);
switch(c)
{
	case 1:
		printf("\nNumber of Processes: ");
		scanf("%d",&n);
		printf("\nNumber of resources: ");
		scanf("%d",&m);
		av[m]=999;
		for(i=0;i<m;i++)
		r[i] = i+65;
		printf("\n\n");
		for(i=0;i<m;i++)
		{
		printf("\nNumber of Available instances of %c:",r[i]);
		scanf("%d",&av[i]);
		}
		printf("\n\n");
		for(i=0;i<n;i++)
		{
		printf("\nMaximum requirement for P%d: ",i);
		for(j=0;j<m;j++)
		scanf("%d",&max[i][j]);
		a[i] = 0;
		}
		for(i=0;i<n;i++)
		{
		printf("\nAllocated instances to P%d: ",i);
		for(j=0;j<m;j++)
		scanf("%d",&alloc[i][j]);
		}
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
		need[i][j] = max[i][j] - alloc[i][j];
		ne[i][j] = need[i][j];
		}
	break;
	case 2:
		printf("\n\n Alloc Max Need Avail\n");
		for(i=0;i<4;i++)
		{
		printf(" ");
		for(j=0;j<m;j++)
		printf("%c",r[j]);
		}
		for(i=0;i<n;i++)
		{
		printf("\nP%d ",i);
		for(j=0;j<m;j++)
		printf("%d",alloc[i][j]);
		printf(" ");
		for(j=0;j<m;j++)
		printf("%d",max[i][j]);
		printf(" ");
		for(j=0;j<m;j++)
		printf("%d",ne[i][j]);
		if(i==0)
		{
		printf(" ");
		for(j=0;j<m;j++)
		printf("%d",av[j]);
		}
		}
	break;
	case 3:
		while(flag!=1)
		{
		for(i=0;i<=n;i++)
		{
		if(a[i]==0)
		break;
		if(i==n)
		flag = 1;
		}
		for(i=k+1;i<=n+k;i++)
		{
		flag2=0;
		if(i>=n)
		p=i-n;
		else
		p=i;
		for(j=0;j<=m;j++)
		{
		if(j==m && a[p]!=1)
		{
		for(l=0;l<m;l++)
		{
		need[p][l]=0;
		av[l] = av[l] + alloc[p][l];
		flag2=1;
		}
		a[p]=1;
		}
		else
		{
		if(need[p][j]>av[j])
		break;
		}
		}
		if(flag2==1)
		break;
		}
		k = p;
		an[count] = k;
		count++;
		}
		printf("\n\nSafety Sequence:\n");
		for(i=0;i<n;i++)
		printf("<P%d>",an[i]);
	break;
	case 4:
		return;
	default:
		printf("\nInvalid choice!");
	break;
	}
}
return 0;
}

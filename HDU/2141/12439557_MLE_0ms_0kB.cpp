#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num1[1005]={0};
int num[2][505]={0};
int num2[505]={0};
int cmp(void const*a, void const*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int a[3];
	int cas=1;
	while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF)
	{
		int i,j;
		for(i=0; i<2; i++)
			for(j=0; j<a[i]; j++)
				scanf("%d",&num[i][j]);
		for(i=0; i<a[2]; i++)
			scanf("%d",&num2[i]);
		int l=0;
		for(i=0; i<a[0]; i++)
			for(j=0; j<a[1] ;j++)
				num1[l++]=num[0][i]+num[1][j];
		qsort(num1, l-1, sizeof(int), cmp);
		int s;
		scanf("%d",&s);
		printf("Case %d:\n",cas++);
		while(s--)
		{
			int flag=0;
			int x1,x2;
			scanf("%d",&x1);
			for(i=0; i<a[2]; i++)
			{
				x2=x1-num2[i];
				int mid,left=0,right=l-1;
				while(left<=right)
				{
					mid=(left+right)/2;
					if(num1[mid]>x2)
						right=mid-1;
					else if(num1[mid]<x2)
						left=mid+1;
					else
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
		memset(num2, 0, sizeof(num2));
		memset(num1, 0, sizeof(num1));
		memset(num, 0, sizeof(num));
	}
	return 0; 
}
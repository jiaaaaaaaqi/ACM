#include<stdio.h>
#include<string.h>
int maxarr(int a[], int n)
{
	int i,j;
	int sum=0;
	int max=a[1];
	for(i=1; i<=n; i++)
	{
		sum+=a[i];
		if(sum<0)
			sum=0;
		if(sum>max)
			max=sum;
	}
	return max;
}
int arr[1000][1000]={0};
int sum[1000]={0};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%d",&arr[i][j]);
		
		int ans=0;
		int sum_=0;
		for(i=1; i<=n; i++)
		{
			memset(sum, 0, sizeof(sum));
			for(j=i; j<=n; j++)
			{
				for(k=1; k<=n; k++)
					sum[k]+=arr[j][k];
				
				sum_=maxarr(sum, n+1);

				if(sum_>ans)
					ans=sum_;
			}
		}
		printf("%d\n",ans);
		memset(arr, 0, sizeof(arr));
		memset(sum, 0, sizeof(sum));
	}
	return 0;
} 

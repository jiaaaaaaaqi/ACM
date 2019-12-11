#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int num[300000]={0};
int a[505]={0};
int b[505]={0};
int c[505]={0};
int main()
{
	int a1,a2,a3;
	int cas=1;
	while(scanf("%d%d%d",&a1,&a2,&a3)!=EOF)
	{
		long long int i,j;
		for(i=0; i<a1; i++)
			scanf("%d",&a[i]);
		for(i=0; i<a2; i++)
			scanf("%d",&b[i]);
		for(i=0; i<a3; i++)
			scanf("%d",&c[i]);
		int l=0;
		for(i=0; i<a1; i++)
			for(j=0; j<a2; j++)
				num[l++]=a[i]+b[j];
		sort(num, num+l);
		sort(c, c+a3);
		int T;
		scanf("%d",&T);
		printf("Case %d:\n",cas++);
		while(T--)
		{
			int flag=0;
			int x1,x2;
			scanf("%d",&x1);
			for(i=0; i<a3; i++)
			{
				x2=x1-c[i];
				int mid,left=0,right=l-1;
				while(left<=right)
				{
					mid=(left+right)>>1;
					if(num[mid]>x2)
						right=mid-1;
					else if(num[mid]<x2)
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
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(num, 0, sizeof(num));
	}
	return 0;
}

#include<stdio.h>
#include<string.h>
int max_(int a , int b)
{
	return a>b ? a:b;
}
int h[1005][1005]={0};
int l[1005]={0};
int r[1005]={0};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char c[2];
		int i,j,k;
		int m,n;
		scanf("%d%d",&n,&m);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
			{
				scanf("%s",c);
				if(c[0]=='R')
					h[i][j]=0;
				else if(c[0]=='F')
					h[i][j]=h[i-1][j]+1; 
			}
		int ans=0;
		for(i=1; i<=n; i++)
		{
			memset(l, 0, sizeof(l));
			memset(r, 0, sizeof(r));
			for(j=1; j<=m; j++)
				l[j]=r[j]=j;
			h[i][0]=h[i][m+1]=-1;
			for(j=1; j<=m; j++)
				while(h[i][l[j]-1]>=h[i][j])
					l[j]=l[l[j]-1];
			for(j=m; j>=1; j--)
				while(h[i][r[j]+1]>=h[i][j])
					r[j]=r[r[j]+1];
			for(j=1; j<=m; j++)
				ans = ans>h[i][j]*(r[j]-l[j]+1) ? ans:h[i][j]*(r[j]-l[j]+1); 
		}
		printf("%d\n",ans*3);
	}
	return 0;
}
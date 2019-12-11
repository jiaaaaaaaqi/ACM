#include<stdio.h>
#include<string.h>
char s[1005][1005]={0};
int h[1005][1005]={0};
int l[1005]={0};
int r[1005]={0};
int max_(int a, int b)
{
	return a>b ? a:b;
}
int solve(int n, int m)
{
	int ans=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
			l[j]=r[j]=j;
		h[i][0]=h[i][m+1]=-1;
		for(int j=1; j<=m; j++)
			while(h[i][l[j]-1]>=h[i][j])
				l[j]=l[l[j]-1];
		for(int j=m; j<=1; j--)
			while(h[i][r[j]+1]>=h[i][j])
				r[j]=r[r[j]+1];
		for(int j=1; j<=m; j++)
			ans=ans>h[i][j]*(r[j]-l[j]+1) ? ans:h[i][j]*(r[j]-l[j]+1);
	} 
	return ans;
}
int main()  
{
	int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
		int ans=0;
		int preans=0;
		for(int i=1; i<=n; i++)
			scanf("%s",s[i]+1);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(s[i][j]=='a'||s[i][j]=='y'||s[i][j]=='z'||s[i][j]=='w')
					h[i][j]=h[i-1][j]+1;
				else
					h[i][j]=0;
			}
		preans=solve(n,m);
		ans=ans>preans ? ans:preans;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(s[i][j]=='b'||s[i][j]=='x'||s[i][j]=='z'||s[i][j]=='w')
					h[i][j]=h[i-1][j]+1;
				else
					h[i][j]=0;
			}
		preans=solve(n,m);
		ans=ans>preans ? ans:preans;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
			{
				if(s[i][j]=='c'||s[i][j]=='y'||s[i][j]=='z'||s[i][j]=='x')
					h[i][j]=h[i-1][j]+1;
				else
					h[i][j]=0;
			}
		preans=solve(n,m);
		ans=ans>preans ? ans:preans;		
		printf("%d\n",ans);
	}
	return 0;
}
#include<stdio.h>
int ans[100005]={0};
int fa[100005]={0};
int fu[100005]={0};
int fv[100005]={0};
int find(int a)
{
	return fa[a]==-1 ? a:find(fa[a]);
}
int bind(int a, int b)
{
	int u=find(a);
	int v=find(b);
	if(u==v)
		return 0;
	else
	{
		fa[u]=v;
		return 1;
	}
}
int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		int i;
		for(i=0; i<M; i++)
		{
			scanf("%d%d", &fu[i], &fv[i]);
			fa[i]=-1;
		}
		for(i=M-1; i>=0; i--)
		{
			if(bind(fu[i], fv[i]))
			{
				ans[i]=N;
				N--;
			}
			else
				ans[i]=N;
		}
		for(i=0; i<M; i++)
		{
			printf("%d\n",ans[i]);
		}
	} 
	return 0;
}
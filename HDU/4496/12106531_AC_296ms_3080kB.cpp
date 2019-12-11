#include<stdio.h>
#include<string.h>
int ans[100005]={0};
int fa[100005]={0};
int fu[100005]={0};
int fv[100005]={0};
int find(int a)
{
	return fa[a]==-1 ? a:fa[a]=find(fa[a]);
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
			scanf("%d%d", &fu[i], &fv[i]);
		memset(fa, -1, sizeof(fa));
		for(i=M-1; i>=0; i--)
		{
			ans[i]=N;
			if(bind(fu[i], fv[i]))
				N--;
		}
		for(i=0; i<M; i++)
		{
			printf("%d\n",ans[i]);
		}
		memset(fu, 0, sizeof(fu));
		memset(fv, 0, sizeof(fv));
		memset(ans, 0, sizeof(ans));
	} 
	return 0;
}
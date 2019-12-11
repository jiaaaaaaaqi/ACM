#include<stdio.h>
#include<string.h>

int fa[100005];
int fu[100005];
int fv[100005];
int num[100005];

void init()
{
	memset(fu, 0, sizeof fu);
	memset(fv, 0, sizeof(fv));
	memset(num, 0, sizeof(num));
	for(int i=0; i<100005; i++)
		fa[i]=i;
}

int find(int x)
{
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}

int bind(int u, int v)
{
	int x=find(u);
	int y=find(v);
	if(x!=y)
	{
		fa[x]=y;
		return 1;
	}
	else
		return 0;
}

int main()
{
	int u,v;
	while(scanf("%d%d",&u, &v), !(u==-1&&v==-1))
	{
		if(u==0&&v==0)
		{
			printf("Yes\n");
			continue;
		}
		init();
		fu[0]=u, num[u]=1;
		fv[0]=v, num[v]=1;
		int j=1;
		int sum=2;
		while(scanf("%d%d",&u, &v), u||v)
		{
			fu[j]=u;
			fv[j]=v;
			j++;
			if(num[u]==0)
				sum++, num[u]=1;
			if(num[v]==0)
				sum++, num[v]=1;
		}
		
		if(sum-1!=j)
		{
			printf("No\n");
			continue;
		}
		
		int flag=0;
		for(int i=0; i<j; i++)
		{
			if(!bind(fu[i], fv[i]))
			{
				flag=1;
				break;
			}
		}
		
		if(flag)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}

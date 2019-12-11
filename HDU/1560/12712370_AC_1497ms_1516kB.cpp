#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char str[10][10]={0};
int deep, ans, n;
char size[10]={0};
char DNA[4]={'A', 'T', 'C', 'G'};

void dfs(int cnt, int len[])
{
	if (cnt>deep)
		return ;
	int maxn=0;
	for (int i=0; i<n; i++)
		maxn=max(size[i]-len[i], maxn);
	if(maxn==0)
	{
		ans=cnt;
		return ;
	}
	if(cnt+maxn>deep)
		return ;
	int pos[10]={0};
	for(int i=0; i<4; i++)
	{
		int flag=0;
		for(int j=0; j<n; j++)
		{
			if(str[j][len[j]]==DNA[i])
			{
				flag=1;
				pos[j]=len[j]+1;
			}
			else
				pos[j]=len[j];
		}
		if(flag)
			dfs(cnt+1, pos);
		if(ans!=-1)
			return ;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		memset(str, 0, sizeof(str));
		deep=0;
		ans=-1;
		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			scanf("%s", str[i]);
			size[i]= strlen(str[i]);
			deep=deep > size[i] ? deep:size[i];
		}
		int pos[10]={0};
		while (1)
		{
			dfs(0,pos);
			if (ans!=-1)
				break;
			deep++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
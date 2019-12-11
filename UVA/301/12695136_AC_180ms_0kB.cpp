#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int beg;
	int end;
	int num;
};
int ans;
int m,sta,n;
node p[30];
int peo[30]={0};
bool cmp(node a, node b)
{
	if(a.beg==b.beg)
		return a.end<b.end;
	else
		return a.beg<b.beg;
}
void dfs(int ding, int money)
{
	if(ding==n)
	{
		ans=max(ans, money);
		return ;
	}
	
	int flag=1; 
	for(int i=p[ding].beg+1; i<=p[ding].end; i++)
	{
		if(peo[i]+p[ding].num>m)
		{
			flag=0;
			break ;
		}
	}
	
	if(flag==1)
	{
		for(int i=p[ding].beg+1; i<=p[ding].end; i++)
			peo[i]+=p[ding].num;
		
		dfs(ding+1, money+(p[ding].end-p[ding].beg)*p[ding].num);
		
		for(int i=p[ding].beg+1; i<=p[ding].end; i++)
			peo[i]-=p[ding].num;
	}
	dfs(ding+1, money);
}
int main()
{
	while(scanf("%d%d%d",&m, &sta, &n), m||sta||n)
	{
		for(int i=0; i<n; i++)
			scanf("%d%d%d",&p[i].beg, &p[i].end, &p[i].num);
		sort(p, p+n, cmp);
		memset(peo, 0, sizeof(peo));
		ans=0;
		dfs(0, 0);
		printf("%d\n", ans);
		memset(peo, 0, sizeof(peo));
	}
	return 0;
}
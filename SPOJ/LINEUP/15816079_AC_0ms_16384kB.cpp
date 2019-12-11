#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 10005;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

struct AA
{
	int v,id;
};

vector<AA>qu[20];
int T, tol;
ll ans;
bool vis[20];

void dfs(int hang,ll fen)
{
	if(hang==12)
	{
		ans=max(fen,ans);
		return ; 
	}
	int len=qu[hang].size();
	for(int i=0;i<len;i++)
	{
		int lie=qu[hang][i].id;
		if(!vis[lie])
		{
			vis[lie]=1;
			dfs(hang+1,fen+qu[hang][i].v);
			vis[lie]=0;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=11;i++)
		{
			qu[i].clear();
			for(int j=1;j<=11;j++)
			{
				AA tmp;
				scanf("%d",&tmp.v);
				tmp.id=j;
				if(tmp.v)
				{
					qu[i].push_back(tmp);
				}
			}
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
	return 0;
}

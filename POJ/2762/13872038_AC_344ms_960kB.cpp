
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
const int maxn=1010;
const int maxm=6010;
using namespace std;

int h,n,m,in[maxn];
int sta[maxn],top,vis[maxn],dfn[maxn],low[maxn],ccnt,id;
vector<int> e[maxn];
vector<int> edge[maxn];
vector<int> part[maxn];
int inpart[maxn];

void tarjan(int x)
{
    int i,j;
    dfn[x]=low[x]=id++;
    vis[x]=1;
    sta[++top]=x;
    for(i=0;i<e[x].size();i++)
    {
        j=e[x][i];
        if(dfn[j]==-1)
        {
            tarjan(j);
            low[x]=min(low[x],low[j]);
        }
        else if(vis[j])
            low[x]=min(low[x],dfn[j]);
    }
    if(dfn[x]==low[x])
    {
        ccnt++;
        do
        {
            j=sta[top--];
            vis[j]=0;
            part[ccnt].push_back(j);
            inpart[j]=ccnt;
        }while(j!=x);
    }
}

void solve()
{
    memset(sta,-1,sizeof sta);
    memset(vis,0,sizeof vis);
    memset(dfn,-1,sizeof dfn);
    memset(low,-1,sizeof low);
    top=ccnt=id=0;
    for(int i=1;i<=n;i++)
            if(dfn[i]==-1)
                tarjan(i);
}

int topo()
{
    queue<int> q;
    for(int i=1;i<=ccnt;i++)
        if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        if(q.size()>1) return 0;
        int x=q.front();
        q.pop();
        for(int i=0;i<edge[x].size();i++)
        {
            in[edge[x][i]]--;
            if(in[edge[x][i]]==0) q.push(edge[x][i]);
        }
    }
    return 1;
}

int main()
{
    int T,a,b,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<=n;i++)
        {
            part[i].clear();
            e[i].clear();
            edge[i].clear();
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            e[a].push_back(b);
        }
        solve();
        memset(in,0,sizeof in);
        int flag=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<e[i].size();j++)
            {
                a=inpart[i];
                b=inpart[e[i][j]];
                if(a!=b)
                {
                    in[b]++;
                    edge[a].push_back(b);
                }
            }
        }
        if(topo())
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


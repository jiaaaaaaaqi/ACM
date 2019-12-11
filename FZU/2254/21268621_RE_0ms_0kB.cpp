#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#define lowbit(x) (x&(-x))
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=a;i>=n;i--)
#define mem(ar,num) memset(ar,num,sizeof(ar))
#define debug(x) cout << #x << ": " << x << endl
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int    prime = 999983;
const int    INF = 0x7FFFFFFF;
const LL     INFF =0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const double inf = 1e18;
const double eps = 1e-6;
const LL     mod = 1e9 + 7;
const int    maxn = 1e5 + 7;
const int    maxm = 4e6 + 7;

int n;
int head[maxm], edge_num;

struct Edge{
    int to;
    int w;
    int next;
}edge[maxn];

void init(){
    for(int i = 0; i <= n; i++){
        head[i] = -1;
    }
    edge_num = 0;
}
void add_edge(int u,int v,int w){
    edge[edge_num].to = v;
    edge[edge_num].w = w;
    edge[edge_num].next = head[u];
    head[u] = edge_num ++;
}

struct Node{
    int to,w;
    Node(){}
    Node(int to,int w): to(to), w(w){}
    friend bool operator< (const Node &a, const Node &b){
        return a.w > b.w;
    }
};

bool vis[maxn];

void prim()
{
    int select = 0,select_num = 0;
    for(int i = 0; i <= n; i++){
        vis[i] = false;
    }
    priority_queue<Node> que;
    que.push(Node(0,0));

    while(!que.empty()){
        Node now = que.top();
        que.pop();
        if(vis[now.to]) continue;
        vis[now.to] = true;
        select += now.w;
        select_num ++;
        for(int i = head[now.to]; ~i; i = edge[i].next){
            int to = edge[i].to;
            int w = edge[i].w;
            if(!vis[to]){
                que.push(Node(to,w));
            }
        }
    }
    if(select_num == n + 1){
        printf("%d\n",select);
    }else{
        puts("?");
    }
}
char str[1005][25];
int main()
{
    int w, cnt, m;
    while(~scanf("%d%d%d",&n,&m,&w)){
        init();
        for(int i = 1; i <= n; i++){
            scanf("%s",str[i]);
            for(int j = 1; j < i; j++){
                cnt  = 0;
                for(int k = 0; k < m; k++){
                    if(str[i][k]!=str[j][k]) cnt++;
                }
                add_edge(i,j,w * cnt);
                add_edge(j,i,w * cnt);
            }
            add_edge(0,i,m);
        }
        prim();
    }
    return 0;
}
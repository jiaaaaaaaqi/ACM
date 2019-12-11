#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define M 300001
#define mod 20071027

int tol;
char str[M];
int dp[M];
int node[400001][26];
bool vis[400001];

void init()
{
    memset(node[0], 0, sizeof(node[0]));
    memset(vis,0,sizeof(vis));
    memset(dp, 0, sizeof(dp));
    tol=1;
}

void insert(char *s)
{
    int root = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++)
    {
        int k = s[i] - 'a';
        if(node[root][k] == 0)
        {
            memset(node[tol], 0, sizeof(node[tol]));
            node[root][k] = tol++;
        }
        root = node[root][k];
    }
    vis[root] = 1;
}

void calc(char *str, int len)
{
    int k;
    for(int i=1; i<len; i++)
    {
        int root = 0;
        for(int j=i; j<len; j++)
        {
            k = str[j] - 'a';
            if(node[root][k] == 0)
                break;
            root = node[root][k];
            if(vis[root])
            {
                dp[j] = (dp[i-1] + dp[j]) % mod;
//				printf("dp[%d] = %d\n", j, dp[j]);
            }
        }
    }
}

int main()
{
    int cas = 1, n;
    while(scanf("%s", str+1) != EOF)
    {
        init();
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            char a[100];
            scanf("%s", a);
            insert(a);
        }
        str[0] = '1';
        int len = strlen(str);
        dp[0] = 1;
        calc(str, len);
        printf("Case %d: %d\n", cas++, dp[len - 1]);
    }
    return 0;
}

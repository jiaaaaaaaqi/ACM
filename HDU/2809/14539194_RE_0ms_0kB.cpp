#include<map>
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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 25;
const int maxm = 1 << 8;
const int mod = 200;
using namespace std;

int n, m, tol;
struct Node {
    int ati;
    int def;
    int hp;
    int exp;
};
Node node[maxn];
int dp[1 << 20];

void init() {
    memset(dp, 0,sizeof dp);
    memset(node, 0, sizeof node);
}

int main() {
    int ait, def, hp, upait, updef, uphp;
    while(~scanf("%d%d%d%d%d%d", &ait, &def, &hp, &upait, &updef, &uphp)) {
        init();
        scanf("%d", &n);
        char s[21];
        for(int i=0; i<n; i++)
            scanf("%s%d%d%d%d", s, &node[i].ati, &node[i].def, &node[i].hp, &node[i].exp);
		dp[0] = hp;
        for(int i=0; i<(1<<n); i++) {
            if(dp[i] <= 0)	continue;
            int exp = 0;
            for(int j=0; j<n; j++) {
                if(i & (1 << j)) {
                    exp += node[j].exp;
                }
            }
            int level = exp / 100;
            int tmpait = ait + level * upait;
            int tmpdef = def + level * updef;
            level++;
            for(int j=0; j<n; j++) {
                if(i & (1 << j))	continue;
                int lvbuait = max(1, tmpait - node[j].def);
                int jait = max(1, node[j].ati - tmpdef);
                int cnt = node[i].hp / lvbuait;
                if(node[i].hp % lvbuait)	cnt++;
                int lost = jait * (cnt - 1);
                if(lost >= dp[i])	continue;
                int curhp = dp[i] - lost;
                if(exp + node[j].exp >= level * 100) {
                    level++;
                    curhp += uphp;
                }
                int state = i | (1 << j);
                dp[state] = max(dp[state], curhp);
            }
        }
        int ans = dp[(1<<n) - 1];
        if(ans <= 0) {
            printf("Poor LvBu,his period was gone.\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

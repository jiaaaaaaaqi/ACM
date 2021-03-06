#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int len[505];
ull sed = 131;
ull fpow[2005];
ull HAS[505];
ull HASH[505][2005];
char s[505][2005];
bitset<505>st[505];
ull Hash(int id, char *str) {
    int len = strlen(str+1);
    ull ans = 0;
    HASH[id][0] = 0;
    for(int i=1; i<=len; i++) {
        ans = ans * sed + str[i] - 'a' + 1;
        HASH[id][i] = ans;
    }
    return ans;
}

bool find(int id, ull res, char *s, int len1, int len2) {
    for(int i=0; i+len2<=len1; i++) {
        ull tmp = HASH[id][i+len2] - HASH[id][i] * fpow[len2];
        if(tmp == res)
            return true;
    }
    return false;
}

int main() {
    cas = 1;
    scanf("%d", &T);
    fpow[0] = 1;
    for(int i=1; i<=2005; i++)
        fpow[i] = fpow[i-1] * sed;
    while(T--) {
        //mes(s, 0);
        //mes(HAS, 0);
        //mes(HASH, 0);
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
			memset(HASH[i],0,sizeof(HASH[i]));
			st[i].reset();
            scanf("%s", s[i]+1);
            HAS[i] = Hash(i, s[i]);
            len[i] = strlen(s[i]+1);
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
			st[i].set(i);
            for(int j=i-1; j>=1; j--) {
				if(st[i][j]==1){
					st[i] |= st[j];
					continue;
				}
					
                if(!find(i, HAS[j], s[i], len[i], len[j])) 
                    break;
					
				st[i] |= st[j];
            }
            if(st[i].count()!=i)
				ans = i;
        }
        printf("Case #%d: %d\n", cas++, ans ? ans : -1);
    }
    return 0;
}

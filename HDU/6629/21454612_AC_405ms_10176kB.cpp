#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];
int nex[maxn];

void getnex(char *s,int next[]){
    int nn = strlen(s);
    next[0] = nn;
    int p = 0;
    while (p+1 < nn && s[p] == s[p+1]) p++;
    next[1] = p;
    int k = 1, L;
    for (int i = 2; i < nn; i++){
        p =     k + next[k] - 1; L = next[i - k];
        if (i + L <= p) next[i] = L;
        else {
            int j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < nn && s[i + j] == s[j]) j++;
            next[i] = j; k = i;
        
        } 
    }
}
int mx [maxn];

int main() {
    // freopen("in", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        getnex(s, nex);
        int len = strlen(s);
        for(int i=1; i<=len; i++) {
            mx[i] = 0;
        }
        ll ans = 0;
        // printf("%d ", len);
        for(int i=1; i<len; i++) {
            // printf("%d%c", mx[i], i==len-1 ? '\n' : ' ');
            int last = i+nex[i];
            if(last == len) ans += nex[i];
            else    ans += nex[i]+1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
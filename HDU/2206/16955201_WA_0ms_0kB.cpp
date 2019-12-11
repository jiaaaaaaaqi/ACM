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
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];

bool ok(char *s) {
    if(s[1] == '.')		return 0;
    int cnt = 0;
    int len = strlen(s+1);
    for(int i=1; i<=len; i++) {
        if(!isdigit(s[i]) && s[i] != '.')
            return 0;
        if(s[i] == '.') {
            if(i == len || s[i+1] == '.')
                return 0;
            else
                cnt++;
        }
    }
    if(cnt != 3)
        return 0;
    else
        return 1;
}

bool four_digit(char *s) {
    int len = strlen(s+1);
    int a, b, c, d;
    sscanf(s+1, "%d.%d.%d.%d", &a, &b, &c, &d);
    if(a<1 || a>255)	return 0;
    if(b<1 || b>255)	return 0;
    if(c<1 || c>255)	return 0;
    if(d<1 || d>255)	return 0;
    return 1;
}

int main() {
    while(gets(s+1)) {
        if(!ok(s)) {
            printf("NO\n");
            continue;
        }
        if(!four_digit(s)) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
		mes(s, 0);
    }
    return 0;
}

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
const int    maxn = 1e4 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
char ans[55][maxn];
char s[maxn];
char a[maxn];
char b[maxn];

void jian(char *a, char *b) {
    char c[maxn], d[maxn], e[maxn];
    int len1 = strlen(a+1);
    int len2 = strlen(b+1);
    for(int i=1; i<=len1; i++)	c[i] = a[len1-i+1];
    for(int i=1; i<=len2; i++)	d[i] = b[len2-i+1];
    int len = max(len1, len2);
    for(int i=len1+1; i<=len; i++)	c[i] = '0';
    for(int i=len2+1; i<=len; i++)	d[i] = '0';
    for(int i=1; i<=len; i++)
        e[i] = c[i] - d[i] + '0';
    for(int i=1; i<=len; i++) {
        if(e[i] < '0') {
            e[i] += 10;
            e[i+1] -= 1;
        }
    }
    for(; e[len] == '0'; len--);
    for(int i=len; i>=1; i--) {
        a[i] = e[len-i+1];
    }
    a[len+1] = '\0';
}

void solve(char *a, int id) {
    int len = strlen(a+1);
    for(int i=1; i<=len; i++)
        ans[id][i] = a[i];
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        mes(s, 0);
        mes(ans, 0);
        scanf("%s", s+1);
        int cnt = 0;
        while(1) {
            int len = strlen(s+1);
			if(len == 0)	break;
            cnt++;
            mes(a, 0);
            if(len == 1) {
                solve(s, cnt);
                jian(s, s);
                continue;
            }
            int x = (len+1) / 2;
            for(int i=1; i<=x; i++)
                a[i] = s[i];
            int len2 = strlen(a+1);
            b[0] = '\0';
            b[1] = '1';
            b[2] = '\0';
            jian(a, b);
            if(len % 2 == 0) {
                int len1 = strlen(a+1);
                if(len1 == len2) {
                    for(int i=len1, j=1; i>=1; i--, j++) {
                        a[len1+j] = a[i];
                    }
                } else {
                    a[len1+1] = '9';
                    for(int i=len1, j=1; i>=1; i--, j++) {
                        a[len1+j+1] = a[i];
                    }
                }
            } else {
                int len1 = strlen(a+1);
                if(len1 == len2) {
                    for(int i=len1-1, j=1; i>=1; i--, j++) {
                        a[len1+j] = a[i];
                    }
                } else {
                    for(int i=len1, j=1; i>=1; i--, j++) {
                        a[len1+j] = a[i];
                    }
                }
            }
            solve(a, cnt);
            jian(s, a);
        }
        printf("Case #%d:\n", cas++);
        printf("%d\n", cnt);
        for(int i=1; i<=cnt; i++) {
            printf("%s\n", ans[i]+1);
        }
    }
    return 0;
}

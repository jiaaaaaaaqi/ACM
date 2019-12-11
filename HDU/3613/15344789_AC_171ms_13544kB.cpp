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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1005000;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
int a[30];
int p[maxn];
int b[maxn];
bool l[maxn];
bool r[maxn];
char s[maxn];
char str[maxn];

void init() {
    memset(a, 0, sizeof a);
    memset(p, 0, sizeof p);
    memset(b, 0, sizeof b);
    memset(s, 0, sizeof s);
    memset(l, 0, sizeof l);
    memset(r, 0, sizeof r);
    memset(str, 0, sizeof str);
}

void handle() {
    int len = strlen(s);
    str[0] = '$';
    str[1] = '#';
    for(int i=0; i<len; i++) {
        str[2*i+3] = '#';
        str[2*i+2] = s[i];
    }
}

void manacher() {
    int id = 0, mx = 0;
    int len = strlen(str);
    for(int i=1; i<len; i++) {
        if(mx > i)	p[i] = min(mx-i, p[2*id-i]);
        else		p[i] = 1;
        for(; str[i-p[i]] == str[i+p[i]]; p[i]++);
        if(p[i] + i > mx) {
            mx = p[i] + i;
            id = i;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        for(int i=1; i<=26; i++)	scanf("%d", &a[i]);
        scanf("%s", s);
        int len = strlen(s);
        for(int i=0; i<len; i++) {
            if(i == 0)	b[i] = a[s[i] - 'a' + 1];
            else		b[i] = b[i-1] + a[s[i] - 'a' + 1];
        }
        handle();
        manacher();
        int len2 = strlen(str);
//        printf("%s\n", str);
//        for(int i=0; i<len2; i++)	printf("%d%c", p[i], i==len2-1 ? '\n' : ' ');
        for(int i=1; i<len2; i++) {
            int ri = p[i] - 2;
            int lx = i - ri;
            int rx = i + ri;
            if(lx/2-1 == 0) {
//				printf("!!%d %d\n", lx/2-1, rx/2-1);
                l[rx/2-1] = true;
            }
            if(rx/2-1 == len-1) {
//				printf("%d !!%d\n", lx/2-1, rx/2-1);
                r[lx/2-1] = true;
            }
        }
//        for(int i=0; i<len; i++)	printf("%d %d %c\n", l[i], r[i], s[i]);
        int ans = -inf;
        for(int i=0; i<len-1; i++) {
//			for(int j=0; j<=i; j++)	printf("%c", s[j]);
//			printf("   ");
//			printf("%s\n", s+i+1);
            int res = 0;
            if(l[i] == 1)
                res += b[i];
            if(r[i+1] == 1)
                res += b[len-1] - b[i];
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}

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
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 9;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
char a[maxn];
/*------------------------------------------------------------*/
int s[maxn<<1],t[maxn<<1],height[maxn],sa[maxn],rk[maxn],p[maxn],c[maxn],w[maxn],dp[maxn][30];
inline int trans(int n,const char* S) {
    int m=*max_element(S+1,S+1+n);
    for(int i=1; i<=n; ++i) rk[S[i]]=1;
    for(int i=1; i<=m; ++i) rk[i]+=rk[i-1];
    for(int i=1; i<=n; ++i) s[i]=rk[S[i]];
    return rk[m];
}
#define ps(x) sa[w[s[x]]--]=x
#define pl(x) sa[w[s[x]]++]=x
inline void radix(int* v,int* s,int* t,int n,int m,int n1) {
    memset(sa,0,n+1<<2);
    memset(c,0,m+1<<2);
    for(int i=1; i<=n; ++i) ++c[s[i]];
    for(int i=1; i<=m; ++i) w[i]=c[i]+=c[i-1];
    for(int i=n1; i; --i) ps(v[i]);
    for(int i=1; i<=m; ++i) w[i]=c[i-1]+1;
    for(int i=1; i<=n; ++i) if(sa[i]>1 && t[sa[i]-1]) pl(sa[i]-1);
    for(int i=1; i<=m; ++i) w[i]=c[i];
    for(int i=n; i; --i) if(sa[i]>1 && !t[sa[i]-1]) ps(sa[i]-1);
}
inline void SAIS(int n,int m,int* s,int* t,int* p) {
    int n1=0,ch=rk[1]=0,*s1=s+n;
    t[n]=0;
    for(int i=n-1; i; --i) t[i]=s[i]==s[i+1]?t[i+1]:s[i]>s[i+1];
    for(int i=2; i<=n; ++i) rk[i]=t[i-1]&&!t[i]?(p[++n1]=i,n1):0;
    radix(p,s,t,n,m,n1);
    for(int i=1,x,y; i<=n; ++i) if(x=rk[sa[i]]) {
            if(ch<=1 || p[x+1]-p[x]!=p[y+1]-p[y]) ++ch;
            else for(int j=p[x],k=p[y]; j<=p[x+1]; ++j,++k)
                    if((s[j]<<1|t[j])^(s[k]<<1|t[k])) {
                        ++ch;
                        break;
                    }
            s1[y=x]=ch;
        }
    if(ch<n1) SAIS(n1,ch,s1,t+n,p+n1);
    else for(int i=1; i<=n1; ++i) sa[s1[i]]=i;
    for(int i=1; i<=n1; ++i) s1[i]=p[sa[i]];
    radix(s1,s,t,n,m,n1);
}
inline void SA(int n,const char* S) {
    mes(rk, 0);
    int m=trans(++n,S);
    SAIS(n,m,s,t,p);
    for(int i=1; i<n; ++i) rk[sa[i]=sa[i+1]]=i;
    for(int i=1,j,k=0; i<n; ++i) if(rk[i]>1) {
            for(j=sa[rk[i]-1]; S[i+k]==S[j+k]; ++k);
            if(height[rk[i]]=k) --k;
        }
}
/*------------------------------------------------------------*/
ll cnt[maxn];

int main() {
    while(~scanf("%s", a+1)) {
		mes(cnt, 0);
        n = strlen(a+1);
        SA(n, a);
        cnt[1] = n-sa[1]+1;
        for(int i=2; i<=n; i++) {
            cnt[i] = cnt[i-1] + n-sa[i]+1-height[i];
        }
        int q;
        scanf("%d", &q);
        ll l, r, v;
        l = r = 0;
        while(q--) {
            scanf("%lld", &v);
            ll k = (l^r^v)+1ll;
            if(k > cnt[n]) {
                printf("0 0\n");
                l = r = 0;
                continue;
            }
            int p = lower_bound(cnt+1, cnt+1+n, k)-cnt;
            int pl = sa[p];
            int pr = sa[p] + k-cnt[p-1]-1+height[p];
			int len = pr-pl+1;
			if(p != n) {
				int lcp = height[p+1];
				for(int j=p+1; j<=n; j++) {
					lcp = min(lcp, height[j]);
					if(lcp < len)	break;
					if(sa[j] < pl) {
						pl = sa[j];
						pr = sa[j] + k-cnt[j-1]-1+height[j];
					}
				}
			}
            printf("%d %d\n", pl, pr);
            l = pl, r = pr;
        }
    }
    return 0;
}

/*
          .
         ';;;;;.
        '!;;;;;;!;`
       '!;|&#@|;;;;!:
      `;;!&####@|;;;;!:
     .;;;!&@$$%|!;;;;;;!'.`:::::'.
     '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
     :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`    '!%&#########@$!:.
     ;!;;!!;;;;;|$$&@##$;;;::'''''::;;;;|&|%@$|;;;;;;;;;;;;;;;;!$;
     ;|;;;;;;;;;;;;;;;;;;!%@#####&!:::;!;;;;;;;;;;!&####@%!;;;;$%`
    `!!;;;;;;;;;;!|%%|!!;::;;|@##%|$|;;;;;;;;;;;;!|%$#####%;;;%&;
    :@###&!:;;!!||%%%%%|!;;;;;||;;;;||!$&&@@%;;;;;;;|$$##$;;;%@|
    ;|::;;;;;;;;;;;;|&&$|;;!$@&$!;;;;!;;;;;;;;;;;;;;;;!%|;;;%@%.
   `!!;;;;;;;!!!!;;;;;$@@@&&&&&@$!;!%|;;;;!||!;;;;;!|%%%!;;%@|.
%&&$!;;;;;!;;;;;;;;;;;|$&&&&&&&&&@@%!%%;!||!;;;;;;;;;;;;;$##!
!%;;;;;;!%!:;;;;;;;;;;!$&&&&&&&&&&@##&%|||;;;!!||!;;;;;;;$&:
':|@###%;:;;;;;;;;;;;;!%$&&&&&&@@$!;;;;;;;!!!;;;;;%&!;;|&%.
 !@|;;;;;;;;;;;;;;;;;;|%|$&&$%&&|;;;;;;;;;;;;!;;;;;!&@@&'
  .:%#&!;;;;;;;;;;;;;;!%|$$%%&@%;;;;;;;;;;;;;;;;;;;!&@:
  .%$;;;;;;;;;;;;;;;;;;|$$$$@&|;;;;;;;;;;;;;;;;;;;;%@%.
    !&!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|@#;
     `%$!;;;;;;;;;;;$@|;;;;;;;;;;;;;;;;;;;;;;;;!%$@#@|.
       .|@%!;;;;;;;;;!$&%||;;;;;;;;;;;;;;;;;!%$$$$$@#|.
           ;&$!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;%#####|.
           |##$|!;;;;;;::'':;;;;;;;;;;;;;!%$$$@#@;
          ;@&|;;;;;;;::'''''':;;;;;;;|$&@###@|`
        .%##@|;;;;:::''''''''''::;!%&##$'
      `$##@$$@@&|!!;;;:'''''::::;;;;;|&#%.
    ;&@##&$%!;;;;;;::''''''''::;!|%$@#@&@@:
     .%@&$$|;;;;;;;;;;:'''':''''::;;;%@#@@#%.
    :@##@###@$$$$$|;;:'''':;;!!;;;;;;!$#@@#$;`
     `%@$$|;;;;;;;;:'''''''::;;;;|%$$|!!&###&'
     |##&%!;;;;;::''''''''''''::;;;;;;;!$@&:`!'
    :;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:                 !@#$'
      |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:              '%%!%&;
      |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`            '%$|!%&;
      |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:           .|%;:!&%`
      !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;          `%&%!!$&:
      '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;         !$!;:!$&:
       |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'      `%$|%%;|&$'
        |&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
        `%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
        !&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
       '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
       .!%%&%'`|$;       :|$#%|@#&;%#%.
*/
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
#define  INOPEN     freopen("in.txt", "rk", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
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
inline void RMQ_INIT(int n) {
    for(int i=1; i<=n; i++)
        dp[i][0] = height[i];
    for(int j=1; (1<<j)<=n; j++) {
        for(int i=1; i<=n; i++) {
            if(i + (1<<j) - 1 <= n) {
                dp[i][j] = min(dp[i][j-1], dp[i + (1<<(j-1))][j-1]);
            }
        }
    }
}
inline int RMQ_QUERY(int x, int y) {
    if(x > y)	swap(x, y);
    int k = log(y - x + 1) / log(2.0);
    return min(dp[x][k], dp[y - (1<<k) + 1][k]);
}
/*------------------------------------------------------------*/

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", a+1);
        n = strlen(a+1);
        SA(n, a);
        int i=1;
        printf("Case #%d:\n", cas++);
        while(i<=n) {
            int rank = rk[i];
            int ans=0, pos=0;
            int dis = height[rk[i]];
            for(int j=rank; j>=2; j--) {
				dis = min(dis, height[j]);
//                if(dis < ans)	break;
                if((sa[j-1]<i&&dis>ans) || (dis==ans && sa[j-1]<pos)) {
                    ans = dis;
                    pos = sa[j-1];
                }
            }
            if(rank != n) {
				dis = height[rk[i]+1];
                for(int j=rank+1; j<=n; j++) {
					dis = min(dis, height[j]);
//                    if(dis < ans)	break;
                    if((sa[j]<i&&dis>ans) || (dis==ans && sa[j]<pos)) {
                        ans = dis;
                        pos = sa[j];
                    }
                }
            }
            if(ans) {
				printf("%d %d\n", ans, pos-1);
				i += ans;
            } else {
				printf("-1 %d\n", a[i]);
				i++;
            }
        }
    }
    return 0;
}

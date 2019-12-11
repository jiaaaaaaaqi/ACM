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

struct Sam {
	int node[maxn<<1][27], step[maxn<<1], fa[maxn<<1];
	int dp[maxn<<1], tax[maxn<<1], gid[maxn<<1];
	bool vis[maxn<<1];
	int last, sz;
	int newnode() {
		mes(node[++sz], 0);
		dp[sz] = step[sz] = fa[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		last = newnode();
	}
	void insert(int k) {
        int p = last, np = last = newnode();
        dp[np] = 1;
        step[np] = step[p]+1;
        for(; p&&!node[p][k]; p=fa[p])
            node[p][k] = np;
        if(p==0) {
            fa[np] = 1;
        } else {
            int q = node[p][k];
            if(step[q] == step[p]+1) {
                fa[np] = q;
            } else {
                int nq = newnode();
                memcpy(node[nq], node[q], sizeof(node[q]));
                fa[nq] = fa[q];
                step[nq] = step[p]+1;
                fa[np] = fa[q] = nq;
                for(; p&&node[p][k]==q; p=fa[p])
                    node[p][k] = nq;
            }
        }
    }
	void handle() {
		for(int i=0; i<=sz; i++)	tax[i] = 0;
		for(int i=1; i<=sz; i++)	tax[step[i]]++;
		for(int i=1; i<=sz; i++)	tax[i] += tax[i-1];
		for(int i=1; i<=sz; i++)	gid[tax[step[i]]--] = i;
		for(int i=sz; i>=1; i--) {
			int u = gid[i];
			dp[fa[u]] += dp[u];
		}
	}
	int solve(char *s, int len) {
		mes(vis, false);
		int p = 1, res = 0;
		int ans = 0;
		for(int i=1; i<=len+len; i++) {
			int k = s[i]-'a'+1;
			while(p && !node[p][k]) {
				p = fa[p];
				res = step[p];
			}
			if(p == 0) {
				p = 1;
				res = 0;
			} else {
				p = node[p][k];
				res++;
				if(res >= len) {
					int tmp = p;
					while(tmp && !vis[tmp] && !(step[fa[tmp]]+1<=len && len<=step[tmp])) {
						vis[tmp] = true;
						p = fa[tmp];
					}
					if(tmp == 0) {
						tmp = 1;
					} else {
						if(!vis[tmp]) {
							vis[tmp] = true;
							ans += dp[tmp];
						}
					}
				}
			}
		}
		return ans;
	}
//	int query(char *str, int len){
//        int now=1,ans=0,L=0;
//        int vis[maxn<<1];
//        mes(vis, 0);
//        for(int i=1;i<=len+len;i++){
//            int x=str[i]-'a';
//            if(node[now][x]) L++,now=node[now][x];
//            else{
//                while(now&&!node[now][x]) now=fa[now];
//                if(!now) now=1,L=0;
//                else L=step[now]+1,now=node[now][x];
//            }
//            if(i>len&&L>=len){
//                int tmp=now;
//                while(tmp&&!(step[fa[tmp]]+1<=len&&step[tmp]>=len)) tmp=fa[tmp];
//                if(!tmp) tmp=1;
//                if(vis[tmp]!=1) ans+=dp[tmp],vis[tmp]=1;
//            }
//        }
//		return ans;
//    }
} sam;
char s[maxn], t[maxn<<1];

int main() {
	scanf("%s", s+1);
	int slen = strlen(s+1);
	sam.init();
	for(int i=1; i<=slen; i++) {
		sam.insert(s[i]-'a'+1);
	}
	sam.handle();
	scanf("%d", &T);
	while(T--) {
		scanf("%s", t+1);
		int tlen = strlen(t+1);
		for(int i=1; i<=tlen; i++) {
			t[i+tlen] = t[i];
		}
		t[tlen+tlen+1] = '\0';
		int ans = sam.solve(t, tlen);
		printf("%d\n", ans);
	}
	return 0;
}

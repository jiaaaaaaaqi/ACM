/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月08日 星期三 15时00分56秒
 ***************************************************************/

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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e6 + 3;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m, A, B;
int cas, tol, T;

map<int, int> mp;

void handle() {
	mp.clear();
	for(int i='a'; i<='z'; i++) {
		mp[i] = i-'a'+1;
	}
	for(int i='A'; i<='Z'; i++) {
		mp[i] = i-'A'+1;
	}
	int cnt = 26;
	for(int i='0'; i<='9'; i++) {
		if(i=='0')	mp[i] = mp['o'];
		else if(i == '1')	mp[i] = mp['i'];
		else if(i == '3')	mp[i] = mp['e'];
		else if(i == '5')	mp[i] = mp['s'];
		else if(i == '7')	mp[i] = mp['t'];
		else mp[i] = ++cnt;
	}
}
struct AC {
	int node[maxn][35], fail[maxn], cnt[maxn];
	ll dp[10][25][maxn];
	int root, sz;
	int newnode() {
		mes(node[++sz], 0);
		cnt[sz] = 0;
		return sz;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(char *s) {
		int len = strlen(s+1);
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = mp[s[i]];
			if(node[rt][k] == 0)	node[rt][k] = newnode();
			rt = node[rt][k];
		}
		cnt[rt] = 1;
	}
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		fail[root] = root;
		for(int i=1; i<=31; i++) {
			if(node[root][i] == 0) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			cnt[u] |= cnt[fail[u]];
			q.pop();
			for(int i=1; i<=31; i++) {
				if(node[u][i] == 0) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
	ll solve(int A, int B) {
		for(int i=0; i<=7; i++) {
			for(int j=0; j<=B; j++) {
				for(int k=0; k<=sz; k++) {
					dp[i][j][k] = 0;
				}
			}
		}
		dp[0][0][1] = 1;
		for(int i=0; i<B; i++) {
			for(int j=1; j<=sz; j++) {
				if(cnt[j])	continue;
				for(int st=0; st<=7; st++) {
					if(dp[st][i][j] == 0)	continue;
					// printf("dp[%d][%d][%d] = %lld\n", st, i, j, dp[st][i][j]);
					for(int k='a'; k<='z'; k++) {
						int nst = node[j][mp[k]];
						if(cnt[nst])	continue;
						dp[st|1][i+1][nst] += dp[st][i][j];
						dp[st|2][i+1][nst] += dp[st][i][j];
						dp[st|1][i+1][nst] %= mod;
						dp[st|2][i+1][nst] %= mod;
					}
					for(int k='0'; k<='9'; k++) {
						int nst = node[j][mp[k]];
						if(cnt[nst])	continue;
						dp[st|4][i+1][nst] += dp[st][i][j];
						dp[st|4][i+1][nst] %= mod;
					}
				}
			}
		}
		ll ans = 0;
		for(int i=A; i<=B; i++) {
			for(int j=1; j<=sz; j++) {
				if(dp[7][i][j] == 0)	continue;
				// printf("dp[7][%d][%d] = %lld\n", i, j, dp[7][i][j]);
				ans = (ans + dp[7][i][j])%mod;
			}
		}
		return ans;
	}
} ac;
char s[maxn];

int main() {
	handle();
	ac.init();
	scanf("%d%d", &A, &B);
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%s", s+1);
		ac.insert(s);
	}
	ac.build();
	ll ans = ac.solve(A, B);
	printf("%lld\n", ans);
	return 0;
}

/*
3 3
1
a
*/

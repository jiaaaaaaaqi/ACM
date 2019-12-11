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
#define lowbit(x) 	x & (-x)
#define mem(a, b)	memset(a, b, sizeof a)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 10005;
const int    maxm = 100005;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int tol, T;

int k;
char ans[maxn];
char s[maxn];
int node[maxm][26];

void init() {
	tol = 1;
	memset(ans, 0, sizeof ans);
	memset(node[0], 0, sizeof node[0]);
}

void insert(char *str, int len) {
//    for(int i=0; i<len; i++)	printf("%c%c", str[i], i==len-1 ? '\n' : ' ');
	int root = 0;
	int q;
	for(int i=0; i<len; i++) {
		q = str[i] - 'a';
		if(q >= k)	return ;
		if(node[root][q] == 0) {
			memset(node[tol], 0, sizeof node[tol]);
			node[root][q] = tol++;
		}
		root = node[root][q];
	}
	return ;
}

bool dfs(int cnt, int root) {
	if(cnt == m)	return false;
	for(int i=0; i<k; i++) {
		char c = 'a' + i;
		if(node[root][i] == 0) {
			ans[cnt++] = 'a'+i;
			printf("%s\n", ans);
			return true;
		} else {
			ans[cnt++] = 'a'+i;
			if(dfs(cnt, node[root][i]))	return true;
			cnt--;
		}
	}
	return false;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d%d", &n, &m, &k);
		scanf("%s", s+1);
		for(int i=1; i<=n; i++) {
			int len = min(m, n-i+1);
			insert(s+i, len);
		}
		dfs(0, 0);
	}
	return 0;
}
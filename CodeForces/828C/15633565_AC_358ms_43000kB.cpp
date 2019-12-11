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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2e6+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
char tmp[maxn];
char s[maxn];
int fa[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void bind(int u, int v) {
	int x = find(u);
	int y = find(v);
	if(x == y)	return ;
	if(x < y)	fa[x] = y;
	else		fa[y] = x;
	return ;
}

int main() {
	memset(s, 0, sizeof s);
	for(int i=0; i<maxn; i++)	fa[i] = i;
	scanf("%d", &m);
	n = 0;
	int q;
	while(m--) {
		scanf("%s", tmp);
		int len = strlen(tmp);
		scanf("%d", &q);
		while(q--) {
			int pos;
			scanf("%d", &pos);
			n = max(n, pos+len-1);
			for(int i=find(pos); i<pos+len; i=find(i+1)) {
				s[i] = tmp[i-pos];
				bind(i, i+1);
			}
		}
	}
	for(int i=1; i<=n; i++)	printf("%c", s[i] ? s[i] : 'a');
	printf("\n");
	return 0;
}

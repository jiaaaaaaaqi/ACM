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
const int maxn = 1e5+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
int cnt[4][11][10][maxn];
char s[maxn];
int mx;

int getid(char c) {
	if(c == 'A')	return 0;
	if(c == 'T')	return 1;
	if(c == 'C')	return 2;
	if(c == 'G')	return 3;
}

void update(int id, int i, int j, int pos, int val) {
	for(int x=pos; x<=mx; x+=lowbit(x))	cnt[id][i][j][x] += val;
}

int query(int id, int i, int j, int pos) {
	int ans = 0;
	for(int x=pos; x>0; x-=lowbit(x))	ans += cnt[id][i][j][x];
	return ans;
}

void init() {
	for(int i=1; i<=10; i++) {
		for(int j=0; j<mx; j++) {
			update(getid(s[j]), i, j%i, j+1, 1);
		}
	}
}

int main() {
	scanf("%s", s);
	mx = strlen(s);
	memset(cnt, 0, sizeof cnt);
	init();
	int q;
	scanf("%d", &q);
	while(q--) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int pos;
			char tmp[15];
			scanf("%d%s", &pos, tmp);
			for(int i=1; i<=10; i++)	update(getid(s[pos-1]), i, (pos-1)%i, pos, -1);
			for(int i=1; i<=10; i++)	update(getid(tmp[0]), i, (pos-1)%i, pos, 1);
			s[pos-1] = tmp[0];
		} else {
			int l, r;
			char tmp[15];
			scanf("%d%d%s", &l, &r, tmp);
			int len = strlen(tmp);
			int ans = 0;
			for(int i=0; i<len; i++) {
				ans += query(getid(tmp[i]), len, (l+i-1)%len, r) - query(getid(tmp[i]), len, (l+i-1)%len, l-1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

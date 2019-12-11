#include<map>
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
const int maxn = 100005;
const int maxm = 40000;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node{
	ll ned;
	ll pri;
};
Node node[maxn];
deque< pair<int, int> > q;

void init() {
	memset(node, 0, sizeof node);
	q.clear();
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &n, &m);
		bool flag = false;
		ll a, b, c;
		node[0].ned = 0;
		node[0].pri = inf;
		for(int i=1; i<=n; i++)	{
			scanf("%lld%lld%lld", &a, &b, &c);
			node[i].ned = a*b;
			node[i].pri = c;
			if(a*b > m)	flag = true;
		}
		if(flag) {
			printf("Impossible\n");
			continue;
		}
		ll ans = 0;
		int vol = 0;
		int need = 0;
		for(int i=1; i<=n; i++) {
			while(!q.empty() && q.back().second > node[i].pri) {
				vol -= q.back().first;
				q.pop_back();
			}
			q.push_back(make_pair(m-vol, node[i].pri));
			need = node[i].ned;
			vol = m - need;
			while(need) {
				int x = min(q.front().first, need);
				q.front().first -= x;
				need -= x;
				ans += (ll)x * q.front().second;
				if(q.front().first == 0)	q.pop_front();
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

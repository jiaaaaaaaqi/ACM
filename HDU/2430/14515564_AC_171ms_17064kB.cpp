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
const int maxn = 1000005;
const int maxm = 305;
using namespace std;

int n, m, tol;
struct Node{
	int mod;
	int id;
	bool operator < (Node a) const {
		if(mod == a.mod)		return id < a.id;
		else	return mod < a.mod;
	}
};
Node node[maxn];
ll sum[maxn];
deque< pair<int, int> > q;

void init() {
	memset(sum, 0, sizeof sum);
	memset(node, 0, sizeof node);
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		init();
		int p, k;
		scanf("%d%d%d", &n, &p, &k);
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d", &x);
			sum[i] = sum[i-1] + x;
			node[i].mod = sum[i] % p;
			node[i].id = i;
		}
		sort(node+1, node+1+n);
		q.clear();
		ll ans = -1;
		for(int i=1; i<=n; i++) {
			while(!q.empty() && q.back().first > node[i].id)
				q.pop_back();
			while(!q.empty() && node[i].mod - q.front().second > k)
				q.pop_front();
			q.push_back(make_pair(node[i].id, node[i].mod));
			if(q.back().second <= k)
				ans = max(ans, sum[q.back().first]);
			else if(!q.empty() && q.front().first < q.back().first)
				ans = max(ans, sum[q.back().first] - sum[q.front().first]);
		}
		printf("Case %d: ", cas++);
		if(ans == -1)	printf("%I64d\n", ans);
		else	printf("%I64d\n", ans / p);
	}
	return 0;
}

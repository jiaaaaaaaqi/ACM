#include<bits/stdc++.h>

typedef long long int ll;
using namespace std;

const int maxn = 100005; 

int n;

struct Node{
	ll l;
	ll r;
	ll id;
};
Node node[100005];
ll cur[30005];
ll ans[100005];
ll sum[30005];
map<ll, ll> vis;

void init() {
	vis.clear();
	memset(cur, 0, sizeof(cur));
	memset(ans, 0, sizeof(ans));
	memset(sum, 0, sizeof(sum));
	memset(node, 0, sizeof(node));
}

bool cmp(Node a, Node b) {
	if(a.r == b.r)
		return a.l < b.l;
	return a.r < b.r;
}

ll lowbit(ll x) {
	return x & (-x);
}

void update(ll pos, ll val) {
	while(pos <= n) {
		sum[pos] += val;
		pos += lowbit(pos);
	}
}

ll query(ll pos) {
	ll ans = 0;
	while(pos > 0) {
		ans += sum[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			ll x;
			scanf("%lld", &x);
			cur[i] = x;
		}
		int m;
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			ll u, v;
			scanf("%lld%lld", &u, &v);
			node[i].l = u;
			node[i].r = v;
			node[i].id = i;
		}
		sort(node+1, node+1+m, cmp);
		int right = 1;
		for(int i=1; i<=m;) {
			if(node[i].r < right) {
				ll res = query(node[i].r) - query(node[i].l - 1);
				ans[node[i].id] = res;
				i++;
			} else {
				if(vis[cur[right]] == 0) {
					update(right, cur[right]);
					vis[cur[right]] = right;
				} else {
					update(vis[cur[right]], -cur[right]);
					vis[cur[right]] = right;
					update(right, cur[right]);
				}
				right++;
			}
		}
		for(int i=1; i<=m; i++) {
			printf("%lld\n", ans[i]);
		}
	}	
	return 0;
} 

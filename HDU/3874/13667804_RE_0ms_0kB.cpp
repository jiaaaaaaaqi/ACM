#include<bits/stdc++.h>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 50005;

int n;
ll sum[maxn];
ll res[maxn];
int cur[maxn];
int vis[1000005];
struct Node{
	int l;
	int r;
	int id;
};
Node node[200005];

void init() {
	memset(sum, 0, sizeof(sum));
	memset(vis, false, sizeof(vis));
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
	int ans = 0;
	while(pos > 0) {
		ans += sum[pos];
		pos -= lowbit(pos);
	}
	return ans;
}
 
 bool cmp(Node a, Node b) {
 	if(a.r == b.r) 
 		return a.l < b.l;
 	else
 		return a.r < b.r;
 }
 
 void addnode(int l, int r, int i) {
 	node[i].l = l;
 	node[i].r = r;
 	node[i].id = i;
 }
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &cur[i]);
		}
		int m;
		scanf("%d", &m);
		for(int i=1; i<=m; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			addnode(l, r, i);
		}
		sort(node+1, node+1+m, cmp);
		int right = 1;
		for(int i=1; i<=m;) {
			if(node[i].r < right) {
				ll ans = query(node[i].r) - query(node[i].l - 1);
				res[node[i].id] = ans;
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
			printf("%lld\n", res[i]);
		}
	}
	return 0;
}
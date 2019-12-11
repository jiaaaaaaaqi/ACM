#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int mod = 10007;

struct Node{
	int id;
	double val;
	bool operator < (Node b) const{
		if(val != b.val)
			return val > b.val;
		else
			return id < b.id;
	}
}node[maxn];
int ans[maxn];

int main() {
	int n, m, k;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		for(int i=0; i<=m; i++) {
			node[i].val = 0;
		}
		memset(ans, 0, sizeof(ans));
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				double x;
				scanf("%lf", &x);
				node[j].id = j + 1;
				node[j].val += x;
			}
		}
		sort(node, node+m);
		for(int i=0; i<k; i++) {
			ans[i] = node[i].id;
		}
		sort(ans, ans+k);
		for(int i=k-1; i>=0; i--) {
			printf("%d%c", ans[i], i == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 150005;
const int maxm = 1e9;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
map<int, deque<int> > q;

void read(int &x) {
	char ch = getchar();
	x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		tol = 1;
		q.clear();
		int id, u, v, val;
		while(m--) {
			read(id);
			if(id == 1) {
				read(u), read(v), read(val);
				if(v == 0)	q[u].push_front(val);
				else		q[u].push_back(val);
			} else if(id == 2) {
				read(u), read(v);
				if(q[u].empty()) {
					printf("-1\n");
					continue;
				}
				if(v == 0) {
					printf("%d\n", q[u].front());
					q[u].pop_front();
				} else {
					printf("%d\n", q[u].back());
					q[u].pop_back();
				}
			} else {
				read(u), read(v), read(val);
				if(val == 0) {
					q[u].insert(q[u].end(), q[v].begin(), q[v].end());
					q[v].clear();
				} else {
					q[u].insert(q[u].end(), q[v].rbegin(), q[v].rend());
					q[v].clear();
				}
			}
		}
	}
	return 0;
}

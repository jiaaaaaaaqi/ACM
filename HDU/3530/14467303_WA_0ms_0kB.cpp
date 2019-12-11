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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
int num[maxn];
deque<int > qx;
deque<int > qm;

void init() {
	memset(num, 0, sizeof num);
	while(!qx.empty())	qx.pop_back();
	while(!qm.empty())	qm.pop_back();
}

int main() {
    int x, y;
    while(~scanf("%d%d%d", &n, &x, &y)) {
		init();
		int ans = 0;
		for(int i=1; i<=n; i++)	scanf("%d", &num[i]);
		for(int i=1; i<=n; i++) {
			while(!qx.empty() && num[i] > num[qx.back()])
				qx.pop_back();
			while(!qm.empty() && num[i] < num[qm.back()])
				qm.pop_back();
			qx.push_back(i);
			qm.push_back(i);
			int last = 0;
			while(!qx.empty() && !qm.empty() && num[qx.front()] - num[qm.front()] > y) {
				if(qx.front() > qm.front()) {
					last = qm.front();
					qm.pop_front();
				} else if(qx.front() < qm.front()) {
					last = qx.front();
					qx.pop_front();
				} else {
					last = qx.front();
					qx.pop_front();
					qm.pop_front();
				}
			}
			if(!qx.empty() && !qm.empty() && num[qx.front()] - num[qm.front()] >= x) {
				ans = max(ans, i - last);
			}
		}
		printf("%d\n", ans);
    }
	return 0;
}

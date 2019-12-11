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

int num[maxn];
int sum[maxn << 1];
deque< pair<int, int> > q;

void init() {
	q.clear();
	memset(num, 0, sizeof num);
	memset(sum, 0, sizeof sum);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int k;
		init();
		scanf("%d%d", &n, &k);
		m = n + k - 1;
		for(int i=1; i<=n; i++)	{scanf("%d", &num[i]);	sum[i] = sum[i-1] + num[i];}
		for(int i=n+1; i<=2*n; i++)	sum[i] = sum[i-1] + num[i-n];
		for(int i=1; i<=2*n; i++)	printf("%d%c", sum[i], i==2*n ? '\n' : ' ');
		int l, r, ans;
		ans = -inf;
		for(int i=1; i<=m; i++) {
			while(!q.empty() && q.back().second > sum[i])	q.pop_back();
			while(!q.empty() && q.front().first + k < i)	q.pop_front();
			q.push_back(make_pair(i-1, sum[i-1]));
			if(ans < sum[i] - q.front().second) {
				ans = sum[i] - q.front().second;
				l = q.front().first + 1;
				r = i;
				if(r > n)	r = r % n;
			}
		}
		printf("%d %d %d\n", ans, l, r);
	}
	return 0;
}

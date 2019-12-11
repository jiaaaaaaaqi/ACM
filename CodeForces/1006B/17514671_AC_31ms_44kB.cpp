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
const int maxn = 2020;
const int maxm = 205;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
struct Node{
	int num;
	int id;
	bool operator < (Node a) const{
		if(num == a.num)	return id < a.id;
		else	return num > a.num;
	}
};
Node node[maxn];
int ans[maxn];
int x[maxn];

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) {
		scanf("%d", &node[i].num);
		node[i].id = i;
	}
	sort(node + 1, node + n + 1);
	int res = 0;
	for(int i=1; i<=m; i++) {
		ans[i] = node[i].id;
		res += node[i].num;
	}
	sort(ans + 1, ans + m + 1);
//	for(int i=1; i<=m; i++)	printf("%d %d%c", node[i].num, node[i].id,i==m ? '\n' : '\n');
//	for(int i=1; i<=m; i++)	printf("%d%c", ans[i], i==m ? '\n' : ' ');
	int pos = 0;
	for(int i=1; i<=m; i++) {
		if(i != m)
			x[i] = ans[i] - pos;
		else
			x[i] = n - pos;
		pos = ans[i];
	}
	printf("%d\n", res);
	for(int i=1; i<=m; i++)	printf("%d%c", x[i], i==m ? '\n' : ' ');
	return 0;
}
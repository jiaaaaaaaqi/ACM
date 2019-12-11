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
const int maxn = 1005;
const int maxm = 105;
using namespace std;

int n, m, tol;
int num[maxn];
int ans[maxn];

int main() {
	while(~scanf("%d", &n)) {
		tol = 0;
		memset(num, 0, sizeof num);
		memset(ans, 0, sizeof ans);
		for(int i=1; i<=n; i++) scanf("%d", &num[i]);
		for(int i=1; i<=n; i++)	{
			if(num[i + 1] == 1 || i == n) {
				ans[tol++] = num[i];
			}
		}
		printf("%d\n", tol);
		for(int i=0; i<tol; i++) {
			printf("%d%c", ans[i], i == tol - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
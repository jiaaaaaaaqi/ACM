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
const int maxm = 1 << 8;
const int mod = 200;
using namespace std;

int n, m, tol;
int num[maxn];
int tmp[maxn];

int main() {
	scanf("%d", &n);
	memset(tmp, 0, sizeof tmp);
	for(int i=1; i<=n; i++)	scanf("%d", &num[i]);
	sort(num+1, num+n+1);
	int ans = 0;
	int j = 1;
	for(int i=1; i<=n; i++)	tmp[i] = num[i];
	for(int i=1; i<n; i++) {
		for(; j<=n; j++) {
			if(tmp[j] > num[i]) {
				ans++;
				j++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
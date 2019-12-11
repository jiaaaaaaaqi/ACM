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
int num[maxn];

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++)	scanf("%d", &num[i]);
	for(int i=1; i<=n; i++)	num[i] = (num[i] & 1) ? num[i] : num[i] - 1;
	for(int i=1; i<=n; i++)	printf("%d%c", num[i], i == n ? '\n' : ' ');
	return 0;
}
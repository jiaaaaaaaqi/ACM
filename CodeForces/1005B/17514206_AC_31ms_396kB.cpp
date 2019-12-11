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
const int maxn = 200005;
const int maxm = 105;
using namespace std;

int n, m, tol;
char str1[maxn];
char str2[maxn];

int main() {
	memset(str1, 0, sizeof str1);
	memset(str2, 0, sizeof str2);
	while(scanf("%s%s", str1, str2) != EOF) {
		ll len1 = strlen(str1);
		ll len2 = strlen(str2);
		ll i = len1 - 1;
		ll j = len2 - 1;
		ll ans = 0;
		while(str1[i] == str2[j]) {
			ans++;
			i--, j--;
			if(i == -1 || j == -1)	break;
		}
		ll res = len1 + len2 - ans - ans;
		printf("%lld\n", res);
		memset(str1, 0, sizeof str1);
		memset(str2, 0, sizeof str2);
	}
	return 0;
}
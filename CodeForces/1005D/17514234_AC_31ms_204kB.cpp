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
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
char str[maxn];

int main() {
	memset(str, 0, sizeof str);
	while(~scanf("%s", str + 1)) {
		int len = strlen(str + 1);
		int sum = 0;
		int ans = 0;
		int flag = 0;
		for(int i=1; i<=len; i++) {
			sum += (str[i] - '0');
			sum %= 3;
			flag++;
			if(sum == 0 || (str[i] - '0') % 3 == 0 || flag == 3) {
				ans++;
				flag = 0;
				sum = 0;
				continue;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
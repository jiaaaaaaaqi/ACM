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
const int maxn = 10005;
const int mod = 10007;

int n, m;
char str[maxn];

int main() {
	while(~scanf("%s", str)) {
		if(str[0] == '0')
			break;
		int len = strlen(str);
		int ans = 0;
		for(int i=0; i<len; i++) {
			ans += (str[i] - '0');
			while(ans >= 10)
				ans = ans % 10 + ans / 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}

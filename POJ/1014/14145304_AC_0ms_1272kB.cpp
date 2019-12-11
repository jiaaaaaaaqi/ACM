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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;

int n, m;
bool flag;
int num[10];

void init() {
	flag = false;
	memset(num, 0, sizeof(num));
}

void dfs(int now, int val, int pos) {
	if(val == pos) {
		flag = true;
		return ;
	}
	if(flag)	return;
	for(int i=now; i>=1; i--) {
		if(num[i]) {
			if(i + val <= pos) {
				num[i]--;
				dfs(i, val + i, pos);
				if(flag)	return;
			}
		}
	}
}

int main() {
	int cas = 1;
	int a, b, c, d, e, f;
	while(scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f), a || b || c || d || e || f) {
		init();
		int ans = 0;
		num[1] = a;
		ans += a * 1;
		num[2] = b;
		ans += b * 2;
		num[3] = c;
		ans += c * 3;
		num[4] = d;
		ans += d * 4;
		num[5] = e;
		ans += e * 5;
		num[6] = f;
		ans += f * 6;
		if((ans & 1) == 0)
			dfs(6, 0, ans >> 1);
		printf("Collection #%d:\n", cas++);
		flag ? printf("Can be divided.\n\n") : printf("Can't be divided.\n\n");
	}
	return 0;
}

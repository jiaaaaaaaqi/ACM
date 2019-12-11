#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 110;

char str[maxn];

void init() {
	memset(str, 0, sizeof(str));
}

int main() {
	int n;
	while(~scanf("%d", &n)) {
		init();
		scanf("%s", str);
		int ans = 0;
		for(int i=0; i+2<n; i++) {
			if(str[i] == 'x' && str[i+1] == 'x' && str[i+2] == 'x')
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

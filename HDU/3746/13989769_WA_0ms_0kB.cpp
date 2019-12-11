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

const int maxn = 100005;

char str[maxn];
int nex[maxn];

void init() {
	memset(str, 0, sizeof(str));
	memset(nex, 0, sizeof(nex));
}

int getnext() {
	int len = strlen(str);
	int i=0;
	int j=-1;
	nex[0] = -1;
	while(i < len) {
		if(j == -1 || str[i] == str[j]) {
			i++;
			j++;
			nex[i] = j;
		} else {
			j = nex[j];
		}
	}
	return nex[len];
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%s", str);
		int len = strlen(str);
		int x = len - getnext();
		int ans = 0;
		if(len != x && len % x == 0)
			ans = 0;
		else
			ans = len - len % x;
		printf("%d\n", ans);
	}
	return 0;
}

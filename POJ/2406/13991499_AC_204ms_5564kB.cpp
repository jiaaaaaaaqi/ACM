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

typedef unsigned long long int ull;
typedef long long int ll;
using namespace std;

const int maxn = 1000005;

char str[maxn];
int nex[maxn];

void init() {
	memset(str, 0, sizeof(str));
	memset(nex, 0, sizeof(nex));
}

void getnext() {
	int len = strlen(str);
	int i = 0;
	int j = -1;
	nex[0] = -1;
	while(i < len) {
		if(j == -1 || str[i] == str[j]) {
			nex[++i] = ++j;
		} else {
			j = nex[j];
		}
	}
}

int main() {
	while(1) {
		init();
		scanf("%s", str);
		if(strcmp(str, ".") == 0)
			break;
		getnext();
		int len = strlen(str);
		/*
		for(int i=0; i<=len; i++) {
			printf("%d%c", nex[i], i==len ? '\n' : ' ');
		}
		*/
		int ans;
		if(len % (len - nex[len]) == 0)
			ans = len / (len - nex[len]);
		else
			ans = 1;
		printf("%d\n", ans);
	}
	return 0;
}

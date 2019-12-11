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

const int maxn = 400005;

char str[maxn];
int nex[maxn];
int ans[maxn];

void init() {
	memset(str, 0, sizeof(str));
	memset(nex, 0, sizeof(nex));
	memset(ans, 0, sizeof(ans));
}

void getnext() {
	int len = strlen(str);
	int i = 0;
	int j = -1;
	nex[0] = -1;
	while(i < len) {
		if(j == -1 || str[i] == str[j]) 
			nex[++i] = ++j;
		else
			j = nex[j];
	}
	return ;
} 

int main() {
	init();
	while(~scanf("%s", str)) {
		int len = strlen(str);
		getnext();
		/*
		for(int i=0; i<len; i++) {
			printf("%d%c", nex[i], i==len-1 ? '\n' : ' ');
		}
		*/
		int cnt = 0;
		int pos = len - 1;
		while(pos != -1) {
			if(str[pos] == str[len - 1])
				ans[cnt++] = pos + 1;
			pos = nex[pos];
		}
		sort(ans, ans+cnt);
		for(int i=0; i<cnt; i++) {
			printf("%d%c", ans[i], i == cnt-1 ? '\n' : ' ');
		}
		init();
	}
	return 0;
}

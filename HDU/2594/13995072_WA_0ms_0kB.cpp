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

const int maxn = 100005;

char str[maxn];
char str2[maxn];
int nex[maxn];

void init() {
	memset(str, 0, sizeof(str));
	memset(nex, 0, sizeof(nex));
	memset(str2, 0, sizeof(str2));
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
	while(~scanf("%s%s", str, str2)) {
		int lena = strlen(str);
		int lenb = strlen(str2);
		strcat(str, str2);
		int len = strlen(str);
//		printf("%s\n", str);
		getnext();
		len = strlen(str);
		int ans = nex[len];
		while(ans > lena || ans > lenb)
			ans = nex[min(lena, lenb)];
		if(ans == 0)
			printf("0\n");
		else {
			str[ans] = '\0';
			printf("%s %d\n", str, ans);
		}
		init();
	}
	return 0;
}
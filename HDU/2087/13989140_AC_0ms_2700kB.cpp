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

const int maxn = 1000005;
const int maxm = 10005;

int len1, len2;
char str1[maxn];
char str2[maxm];
int nex[maxm];

void init() {
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	memset(nex, 0, sizeof(nex));
}

void getnex() {
	int j = 0;
	int k = -1;
	nex[0] = -1;
	while(j < len2) {
		if(k == -1 || str2[j] == str2[k]) {
			j++;
			k++;
			nex[j] = k;
		} else {
			k = nex[k];
		}
	}
}

int kmp() {
	getnex();
	int res = 0;
	int i = 0, j = 0;
	while(i < len1) {
		if(j == -1 || str1[i] == str2[j]) {
			i++;
			j++;
		} else {
			j = nex[j];
		}
		if(j == len2) {
			j = 0;
			res++;
		}
	}
	return res;
}

int main() {
	int T;
	init();
	while(1) {
		scanf("%s", str1);
		if(strcmp(str1, "#") == 0)
			break;
		scanf("%s", str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		int res = kmp();
		printf("%d\n", res);
		init();
	}
	return 0;
}
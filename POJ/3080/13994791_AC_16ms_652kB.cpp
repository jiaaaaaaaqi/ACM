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

int nex[65];
char tmp[65];
char ans[65];
char str[20][65];

void init() {
	memset(tmp, 0, sizeof(tmp));
	memset(str, 0, sizeof(str));
	ans[0] = 'Z';
}

void getnext(char *str) {
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

bool kmp(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;
	int j = 0;
	while(i < len1) {
		if(j == -1 || str1[i] == str2[j]) {
			i++;
			j++;
		} else {
			j = nex[j];
		}
		if(j == len2)
			return true;
	}
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%s", str[i]);
		}
		int len0 = strlen(str[0]);
		bool ok = false;
		for(int len=len0; len>=3; len--) {
			ok = false;
			for(int i=0; i<=len0-len; i++) {
				memset(tmp, 0, sizeof(tmp));
				strncpy(tmp, str[0] + i, len);
				tmp[len] = '\0';
				getnext(tmp);
				bool flag = true;
				for(int j=1; j<n; j++) {
					if(!kmp(str[j], tmp)) {
						flag = false;
						break;
					}
				}
				if(flag) {
					ok = true;
					if(strcmp(ans, tmp) > 0)
						strcpy(ans, tmp);
				}
			}
			if(ok)
				break;
		}
		if(!ok)
			printf("no significant commonalities\n");
		else
			printf("%s\n", ans);
	}
	return 0;
}


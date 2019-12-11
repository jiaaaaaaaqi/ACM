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

int n, len;
bool flag;
char tmp[15];
char ans[15];
bool vis[15];
char str[15];

void init() {
	memset(tmp, 0, sizeof(tmp));
	memset(ans, 0, sizeof(ans));
	memset(vis, 0, sizeof(vis));
	memset(str, 0, sizeof(str));
}

bool cmp(char a, char b) {
	return a > b;
}

void dfs(int deep, int num) {
	if(deep == 5) {
		if(num == n) {
			memcpy(tmp, ans, sizeof(ans));
			flag = true;
		}
		return ;
	}
	if(flag == true)
		return ;
	for(int i=0; i<len; i++) {
		if(vis[i])
			continue;
		int x = str[i] - 'A' + 1;
		int tmp = x;
		for(int j=0; j<deep; j++) {
			x *= tmp;
		}
		vis[i] = true;
		ans[deep] = str[i];
		if(deep & 1)
			dfs(deep + 1, num - x);
		else
			dfs(deep + 1, num + x);
		vis[i] = false;
	}
	return ;
}

int main() {
	while(1) {
		init();
		flag = false;
		scanf("%d%s", &n, str);
		if(n == 0 && strcmp(str, "END") == 0)
			break;
		len = strlen(str);
		sort(str, str+len, cmp);
		dfs(0, 0);
		if(flag) {
			printf("%s\n", tmp);
		} else {
			printf("no solution\n");
		}
	}
	return 0;
}

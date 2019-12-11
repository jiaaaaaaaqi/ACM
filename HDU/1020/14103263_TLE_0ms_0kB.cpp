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

int num[26];
char str[105];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(num, 0, sizeof(num));
		scanf("%s", str);
		int len = strlen(str);
		for(int i=0; i<len; i++) {
			num[str[i] - 'A']++;
		}
		for(int i=0; i<26; i++) {
			if(num[i] == 0)
				continue;
			else if(num[i] == 1)
				printf("%c", i+'A');
			else
				printf("%d%c", num[i], i+'A');
		}
		printf("\n");
	}
	return 0;
}
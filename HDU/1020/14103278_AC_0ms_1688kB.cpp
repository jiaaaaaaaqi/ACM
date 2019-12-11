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
char str[10005];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(num, 0, sizeof(num));
		scanf("%s", str);
		int len = strlen(str);
		for(int i=0; i<len; i++) {
			char tmp = str[i];
			int num = 0;
			while(str[i] == tmp) {
				num++;
				i++;
			}
			i--;
			if(num == 1)
				printf("%c", tmp);
			else
				printf("%d%c", num, tmp);
		}
		printf("\n");
	}
	return 0;
}
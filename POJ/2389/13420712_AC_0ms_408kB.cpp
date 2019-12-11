#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100;
int num1[maxn];
int num2[maxn];
int ans[2 * maxn];
char str1[maxn];
char str2[maxn];

void init() {
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	memset(str1, 0, sizeof(str1));
	memset(str2, 0, sizeof(str2));
	memset(ans, 0, sizeof(ans));
}

int main() {
	init();
	while(scanf("%s%s", str1, str2) != EOF) {
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int j = 0;
		for(int i=len1-1; i>=0; i--)
			num1[j++] = str1[i] - '0';
		j = 0;
		for(int i=len2-1; i>=0; i--)
			num2[j++] = str2[i] - '0';
		int len3 = len1 + len2;
		for(int i=0; i<len1; i++) {
			for(int j=0; j<len2; j++) {
				ans[i+j] += num1[i] * num2[j];
			}
		}
		for(int i=0; i<len3; i++) {
			ans[i+1] += ans[i] / 10;
			ans[i] %= 10;
		}
		while(ans[len3-1] == 0)
			len3--;
		for(int i=len3-1; i>=0; i--)
			printf("%d", ans[i]);
		printf("\n");
		init();
	}
	return 0;
}
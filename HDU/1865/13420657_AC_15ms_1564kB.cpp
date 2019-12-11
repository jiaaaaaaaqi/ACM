#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

char str[205];
int flag;
int num1[205];
int num2[205];
int num[205];
char ans[205][205];

void addnum(char str1[100], char str2[100]) {
	memset(num, 0, sizeof(num));
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int j=0;
	for(int i=len1-1; i>=0; i--)
		num1[j++] = str1[i] - '0';
	j=0;
	for(int i=len2-1; i>=0; i--)
		num2[j++] = str2[i] - '0';
	int len = max(len1, len2);
	for(int i=0; i<len; i++) {
		num[i] = num1[i] + num2[i];
	}
	int len3;
	for(int i=0; i<len; i++) {
		num[i+1] += num[i] / 10;
		num[i] = num[i] % 10;
	}
	len3 = len;
	if(num[len])
		len3 = len+1;
	j=0;
	for(int i=len3-1; i>=0; i--)
		ans[flag][j++] = num[i] + '0';
}

void handle() {
	memset(ans, 0, sizeof(ans));
	ans[1][0] = '1';
	ans[2][0] = '2';
	for(int i=3; i<=200; i++) {
		flag = i;
		addnum(ans[i-1], ans[i-2]);
	}
}

int main() {
	handle();
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		int len = strlen(str);
		printf("%s\n", ans[len]);
	}
	return 0;
}

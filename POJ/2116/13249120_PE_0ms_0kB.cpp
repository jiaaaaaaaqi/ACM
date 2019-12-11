#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int fib[45];
void handle() {
	memset(fib, 0, sizeof(fib));
	fib[0] = 1;
	fib[1] = 2;
	for(int i=2; i<42; i++)
		fib[i] = fib[i-1] + fib[i-2];
}

int strcalc(char str[], int len) {
	int ans = 0;
	for(int i=0; i<len; i++) {
		ans += (str[i]-'0') * fib[len-i-1];
	}
	return ans;
}

void strchange(char str[90], int num) {
	int ans[90];
	int tol = 0;
	int maxi = 0;
	while(num>0) {
		int x;
		int i=0;
		while(num>=fib[i])
			i++;
		i--;
		num -= fib[i];
		ans[tol++] = i;
		maxi = max(maxi, i);
	}
	memset(str, 0, sizeof(str));
	for(int i=0; i<=maxi; i++)
		str[i] = '0';
	for(int i=0; i<tol; i++) {
		str[maxi-ans[i]] = '1';
	}
}

int main() {
	handle();
	char a[1000];
	char b[1000];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while(scanf("%s%s", a, b) != EOF) {
		char str1[90];
		char str2[90];
		char ans[90];
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		memset(ans, 0, sizeof(ans));
		int len1 = 0;
		int len2 = 0;
		int len3 = 0;
		bool flag = true;
		int len = strlen(a);
		for(int i=0; i<len; i++) {
			if(a[i] == '0' && flag) {
				continue;
			} else if(a[i] == '1') {
				str1[len1++] = a[i];
				flag = false;
			} else if(a[i] == '0' && !flag) {
				str1[len1++] = a[i];
			}
		}
		if(len1 == 0)
			str1[0] = '0';
		flag = true;
		len = strlen(b);
		for(int i=0; i<len; i++) {
			if(b[i] == '0' && flag) {
				continue;
			} else if(b[i] == '1') {
				str2[len2++] = b[i];
				flag = false;
			} else if(b[i] == '0' && !flag) {
				str2[len2++] = b[i];
			}
		}
		if(len2 == 0)
			str2[0] = '0';
		if(strcmp(str1, "0") == 0 && strcmp(str2, "0") == 0) {
			ans[0] = '0';
			str1[0] = '0';
			str2[0] = '0';
		} else {
			int num1, num2, num3;
			if(strcmp(str1, "0") != 0) {
				num1 = strcalc(str1, len1);
				strchange(str1, num1);
			} else
				num1 = 0;
			if(strcmp(str2, "0") != 0) {
				num2 = strcalc(str2, len2);
				strchange(str2, num2);
			} else
				num2 = 0;
			num3 = num1 + num2;
			strchange(ans, num3);
		}
		//printf("%s\n%s\n%s\n", str1, str2, ans);
		len1 = strlen(str1);
		len2 = strlen(str2);
		len3 = strlen(ans);
		int x = len3 - len1 + 2;
		for(int i=0; i<x; i++)
			printf(" ");
		printf("%s\n", str1);
		x = len3 - len2 + 1;
		printf("+");
		for(int i=0; i<x; i++)
			printf(" ");
		printf("%s\n", str2);
		printf("  ");
		for(int i=0; i<len3; i++)
			printf("-");
		printf("\n");
		printf("  ");
		printf("%s\n", ans);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
	return 0;
}

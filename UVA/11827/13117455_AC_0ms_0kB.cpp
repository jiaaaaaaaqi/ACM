#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>

using namespace std;

long long int num[105];

long long int gcd(long long int a, long long b) {
	if(b == 0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

int main() {
	int T;
	char str[1000]= {0};
	scanf("%d", &T);
	getchar();
	while(T--) {
		memset(str, 0, sizeof(str));
		memset(num, 0, sizeof(num));
		int n=0;
		gets(str);
		int len=strlen(str);
		long long int sum = 0;
		for(int i=0; i<=len; i++) {
			if(isdigit(str[i])) {
				sum = sum*10 + str[i] - '0';
			} else if(!isdigit(str[i])) {
				if(sum != 0)
					num[n++] = sum;
				sum = 0;
			}
		}
/*
		for(int i=0; i<n; i++)
			printf("!%d  ", num[i]);
		puts("");
*/
		sort(num, num+n);
		long long int ans = 0;
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				long long int x = gcd(num[i], num[j]);
				ans = max(ans, x);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
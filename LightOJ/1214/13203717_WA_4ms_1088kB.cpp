#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>

using namespace std;

char num[205];

void init() {
	memset(num, 0, sizeof(num));
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		long long int b;
		scanf("%s %lld", num, &b);
		if(b < 0)
			b = -b;
		long long int sum = 0;
		int len = strlen(num);
		for(int i=0; i<len; i++) {
			if(!isdigit(num[i]))	
				continue;
			sum = 10*sum + (num[i]-'0');
			sum %= b;
		}
		if(sum == 0)
			printf("divisible\n");
		else
			printf("not divisible\n");
	}
	return 0;
}

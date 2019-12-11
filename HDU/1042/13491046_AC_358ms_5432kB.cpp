#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int ans[1000000];

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		memset(ans, 0, sizeof(ans));
		int up;
		int digit = 1;
		ans[0] = 1;
		for(int i=2; i<=n; i++) {
			up = 0; 
			for(int j=0; j<digit; j++) {
				int x = i * ans[j] + up;
				ans[j] = x % 10000;
				up = x / 10000;
			}
			if(up) {
				ans[digit++] = up % 10000;
			}
		}
		printf("%d", ans[digit-1]);
		for(int i=digit-2; i>=0; i--) {
			if(ans[i] >= 1000)
				printf("%d", ans[i]);
			else if(ans[i] >= 100)
				printf("0%d", ans[i]);
			else if(ans[i] >= 10)
				printf("00%d", ans[i]);
			else if(ans >=0)
				printf("000%d", ans[i]);
		}
		printf("\n");
	}
	return 0; 
}
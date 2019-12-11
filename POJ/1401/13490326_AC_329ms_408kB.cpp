#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		int ans = 0;
		scanf("%d", &n);
		while(n) {
			ans += n / 5;
			n /= 5;
		}
		printf("%d\n", ans);
	}
	return 0; 
}
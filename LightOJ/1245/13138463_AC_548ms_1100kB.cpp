#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int k = sqrt(n);
		long long int ans = 0;
		for(int i=1; i<=k; i++) {
			ans += n/i;
			if(n/i > n/(i+1))
				ans += (long long int)((n/i-n/(i+1)) * i);
		}
		if(n/k == k)
			ans -= k;
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
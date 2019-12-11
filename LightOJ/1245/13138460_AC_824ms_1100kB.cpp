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
		long long int ans = 0;
		int i;
		for(i=1; i<=sqrt(n); i++) {
			ans += n/i;
			if(n/i > n/(i+1))
				ans += (long long int)((n/i-n/(i+1)) * i);
		}
		i--;
		if(n/i == i)
			ans -= i;
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
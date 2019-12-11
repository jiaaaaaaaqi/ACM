#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const long long int maxn = 0x3f3f3f3f;

long long int calc(long long int n) {
	long long int ans = 0;
	while(n) {
		ans += n/5;
		n /= 5;
	}
	return ans;
}

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int num;
		long long int left = 1;
		long long int right = maxn;
		scanf("%lld", &num);
		while(left <= right) {
			long long int mid = (left + right) >> 1;
			long long int x = calc(mid);
			if(x >= num) 
				right = mid - 1;
			else if (x < num)
				left = mid + 1;
		}
		long long ans = calc(left);
		printf("Case %d: ", cas++);
		if(ans != num)
			printf("impossible\n");
		else
			printf("%lld\n", left);
	}
	return 0;
}

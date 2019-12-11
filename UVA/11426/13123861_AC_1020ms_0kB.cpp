#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=4000001;
long long int phi[maxn];
long long int ans[maxn];

void handle() {
	memset(phi, 0, sizeof(phi));
	memset(ans, 0, sizeof(ans));
	for(int i=1; i<maxn; i++)
		phi[i] = i;
	for(int i=2; i<maxn; i++) {
		if(phi[i] == i) {
			for(int j=i; j<maxn; j+=i) {
				phi[j] = phi[j] / i * (i-1);
			}
		}
	}
	for(int i=1; i<maxn; i++) {
		for(int j=i+i; j<maxn; j+=i) {
			ans[j] += i * phi[j/i];
		}
	}
}

int main() {
	handle();
	long long int n;
	while(scanf("%d", &n), n) {
		long long int res=0;
		for(int i=1; i<=n; i++) {
			res += ans[i];
		}
		printf("%lld\n", res);
	}
	return 0;
}
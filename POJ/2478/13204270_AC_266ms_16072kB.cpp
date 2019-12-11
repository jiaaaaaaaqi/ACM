#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e6;
long long int phi[maxn+10];
long long int ans[maxn+10];

void handle() {
	memset(ans, 0, sizeof(ans));
	for(int i=1; i<=maxn; i++)
		phi[i] = i;
	for(int i=2; i<=maxn; i++) {
		if(phi[i] == i) {
			for(int j=i; j<=maxn; j+=i) {
				phi[j] = phi[j] / i * (i-1);
			}
		}
	}
	for(int i=2; i<=maxn; i++) {
		ans[i] = ans[i-1] + phi[i];
	}
}

int main() {
	int n;
	handle();
	while(scanf("%d", &n), n) {
		printf("%lld\n", ans[n]);
	}
	return 0;
}
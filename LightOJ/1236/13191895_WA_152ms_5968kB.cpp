#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e6;
int tol = 1;
bool ispri[maxn+10];
int pri[maxn+10];

void handle() {
	memset(ispri, true, sizeof(ispri));
	memset(pri, 0, sizeof(pri));
	for(int i=2; i<=1e6; i++) {
		if(ispri[i]) {
			pri[tol++] = i;
			for(int j=2; i*j<=1e6; j++) {
				ispri[i*j] = false;
			}
		}
	}
}

int main() {
	handle();
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int n, num;
		scanf("%lld", &n);
		long long int ans = 1;
		num = n;
		for(int i=1; i<tol && pri[i]<=num; i++) {
			int cnt = 0;
			while(num%pri[i] == 0) {
				cnt++;
				num /= pri[i];
			}
			ans *= (2*cnt + 1);
		}
		if(num>1) {
			ans *= 3;
		}
		ans ++;
		ans /= 2;
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
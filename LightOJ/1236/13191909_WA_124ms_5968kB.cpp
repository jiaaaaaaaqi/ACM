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
	for(int i=2; i<=maxn; i++) {
		if(ispri[i]) {
			pri[tol++] = i;
			for(int j=2; i*j<=maxn; j++) {
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
		int ans = 1;
		num = n;
		for(int i=1; i<tol && pri[i]*pri[i]<=num; i++) {
			if(num%pri[i] == 0) {
				int cnt = 0;
				while(num%pri[i] == 0) {
					cnt++;
					num /= pri[i];
				}
				ans *= (2*cnt + 1);
			}
		}
		if(num>1) {
			ans *= 3;
		}
		ans = (ans+1) / 2;
		printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}
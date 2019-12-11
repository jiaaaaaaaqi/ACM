#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
typedef unsigned long long ull;

using namespace std;

const int maxn = 1e7;
bool vis[100];
ull ans[maxn];

void handle() {
	for(int i=4; i<70; i++) {
		bool flag = false;
		for(int j=2; j*j<=i; j++) {
			if(i%j == 0) {
				flag = true;
				break;
			}
		}
		if(flag)
			vis[i] = true;
	}
}

ull fast_pow(ull a, ull b) {
	ull ans = 1;
	while(b) {
		if(b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main() {
	handle();
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	int tol = 0;
	ull n1 = (1<<16);
	for(ull i=2; i<=n1; i++) {
		ull n2 = 64 * log(2) / log(i) - 1;
		for(ull j=4; j<=n2; j++) {
			if(!vis[j])
				continue;
			ans[++tol] = fast_pow(i, j);
		}
	}
	sort(ans, ans + tol);
	tol=unique(ans, ans + tol) - ans;
	for(int i=0; i<tol; i++)
		printf("%llu\n", ans[i]);
	return 0;
}
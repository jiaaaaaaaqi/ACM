#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e7;
bool ispri[maxn];
int pri[maxn/10];
int tol = 0;

void handle() {
	memset(ispri, true, sizeof(ispri));
	memset(pri, 0, sizeof(pri));
	for(int i=2; i<maxn; i++) {
		if(ispri[i]) {
			pri[tol++] = i;
			for(int j=2; i*j<maxn; j++) {
				ispri[i*j] = false;
			}
		}
	}
}

bool judge(long long int x) {
	for(int i=0; i<tol && pri[i]*pri[i] <= x; i++) {
		int cnt = 0;
		if(x % pri[i] != 0)
			continue;
		long long int n = x;
		while(n % pri[i] == 0) {
			cnt++;
			n /= pri[i];
		}
		if(n != 1)
			continue;
		else {
			if(cnt>2 && !(cnt&1))
				return true;
			else
				return false;
		}
	}
	return false;
}

int main() {
	long long int n = 9223372036854775807;
	handle();
	printf("1\n");
	for(long long int i=2; i<=n; i++) {
		if(judge(i))
			printf("%lld\n", i);
	}
	return 0;
}

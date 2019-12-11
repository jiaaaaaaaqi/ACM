#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=1e6;
int tol = 1;
int pri[maxn+10];
bool ispri[maxn+10];

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

int main() {
	handle();
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		int n;
		int ans = 0;
		scanf("%d", &n);
		for(int i=1; i<tol&&pri[i]<=n/2; i++) {
			if(ispri[n-pri[i]])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
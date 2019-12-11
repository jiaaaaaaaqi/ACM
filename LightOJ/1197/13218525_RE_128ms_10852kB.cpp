#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e7;
bool ispri[maxn];

void handle() {
	memset(ispri, true, sizeof(ispri));
	for(int i=2; i<maxn; i++) {
		if(ispri[i]) {
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
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = 0;
		for(int i=a; i<=b; i++) {
			if(ispri[i])
				ans++;
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
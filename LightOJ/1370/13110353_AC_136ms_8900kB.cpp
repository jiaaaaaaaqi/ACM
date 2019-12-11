#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn=1e6+10;
long long int euler[maxn];

void init() {
	for(int i=1; i<maxn; i++)
		euler[i] = i;
	for(int i=2; i<maxn; i++) {
		if(euler[i] == i) {
			for(int j=i; j<maxn; j+=i) {
				euler[j] = euler[j] / i * (i-1);
			}
		}
	}
}

int main() {
	init();
	int T;
	int cas=1;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		long long int ans=0;
		while(n--) {
			int x;
			scanf("%d", &x);
			int pos = x+1;
			while(x > euler[pos]) {
				pos++;
			}
//			printf("%d  ", pos);
			ans += pos;
		}
		printf("Case %d: %lld Xukha\n", cas++, ans);
	}
	return 0;
} 
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const long long int maxn = 100020000;
bool ispri[maxn]; 
bool vis[10005];

void handle() {
	memset(ispri, true, sizeof(ispri));
	memset(vis, false, sizeof(vis));
	for(long long int i = 2; i < maxn; i++) {
		if(!ispri[i])
			continue;
		for(long long int j = 2; j*i < maxn; j++) {
			ispri[i*j] = false;
		}
	}
	for(int i=0; i<10000; i++) {
		long long int x = i*i+i+41;
		if(ispri[x])
			vis[i] = true;
	}
}

int main() {
	int a, b;
	handle();
	while(scanf("%d%d", &a, &b) != EOF) {
		double ans = 0.0;
		for(int i=a; i<=b; i++) {
			if(vis[i]) {
				ans += 1.0;
			}
		}
		ans = ans / (b-a+1);
		ans *= 10000;
		ans = (int)(ans+0.5);
		ans = (double)(ans / 100);
		printf("%.2lf\n", ans);
	}
	return 0;
}
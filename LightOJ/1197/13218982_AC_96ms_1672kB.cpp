#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 1e5;
bool ispri[maxn];
bool vis[maxn];
int pri[maxn];
int tol = 0;

void handle() {
	memset(pri, 0, sizeof(pri));
	memset(ispri, true, sizeof(ispri));
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
		int a, b;
		scanf("%d%d",&a, &b);
		if(a <= 2)
			a = 2;
		int r = b-a;
		memset(vis, true, sizeof(vis));
		for(int i=0; i<tol && pri[i]*pri[i]<=b; i++) {
			int j;
			if(a%pri[i] == 0)
				j = 0;
			else
				j = pri[i] - a%pri[i];
			if(a + j == pri[i])
				j += pri[i];
			for( ; j<=r; j+=pri[i])
				vis[j] = false;
		}
		int ans = 0;
		for(int i=0; i<=r; i++)
			if(vis[i])
				ans++;
		printf("Case %d: %d\n",cas++, ans);
	}
	return 0;
}
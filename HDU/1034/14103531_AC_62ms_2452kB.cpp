#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int mod = 10007;

int now[maxn];
int nex[maxn]; 

int n;
bool ok() {
	for(int i=1; i<n; i++) {
		if(now[i] != now[i-1])
			return false;
	}
	return true;
}

int main() {
	while(scanf("%d", &n), n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &now[i]);
		}
		int ans = 0;
		while(1) {
			memset(nex, 0, sizeof(nex));
			for(int i=0; i<n; i++) {
				now[i] /= 2;
			}
			for(int i=0; i<n; i++) {
				if(i == 0)
					nex[0] = now[0] + now[n - 1];
				else
					nex[i] = now[i] + now[i-1];
			}
			for(int i=0; i<n; i++) {
				if(nex[i] & 1)
					nex[i]++;
			}
			memcpy(now, nex, sizeof(nex));
			ans++;
			if(ok())
				break;
		}
		printf("%d %d\n", ans, now[0]);
	}
	return 0;
}
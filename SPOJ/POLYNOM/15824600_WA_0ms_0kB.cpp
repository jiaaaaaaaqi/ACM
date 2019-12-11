#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) 	x & (-x)
#define fi			first
#define	se			second
#define INOPEM  	freopen("in.txt", "r", stdin)
#define OUTOPEN 	freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 550;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int tol, T;
ll a[maxn];
ll a1[maxn];
ll a2[maxn];
ll a3[maxn];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)	scanf("%lld", &a[i]);
        for(int i=2; i<=n; i++) {
			a1[i-1] = a[i] - a[i-1];
        }
        bool flag = true;
        n--;
        for(int i=2; i<=n; i++) {
			if(a1[i] != a1[i-1]) {
				flag = false;
				break;
			}
        }
        if(!flag) {
			printf("NO\n");
			continue;
        }

		for(int i=2; i<=n; i++) {
			a2[i-1] = a1[i] - a1[i-1];
		}
		flag = true;
		n--;
		for(int i=2; i<=n; i++) {
			if(a2[i] != a2[i-1]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			printf("NO\n");
			continue;
		}
		
		for(int i=2; i<=n; i++) {
			a3[i-1] = a2[i] - a2[i-1];
		}
		flag = true;
		n--;
		for(int i=2; i<=n; i++) {
			if(a3[i] != a3[i-1]) {
				flag = false;
				break;
			}
		}
		if(!flag) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
    }
    return 0;
}

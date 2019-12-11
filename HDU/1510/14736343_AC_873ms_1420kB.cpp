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
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 30005;
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol;

char str[105][105];
int sum[105][105];

void init() {
    memset(str, 0, sizeof str);
    memset(sum, 0, sizeof sum);
}

void update(int x, int y) {
	for(int i=x; i<=n; i+=lowbit(i))
		for(int j=y; j<=n; j+=lowbit(j))
			sum[i][j]++;
}

int query(int x, int y) {
	int ans = 0;
	for(int i=x; i>0; i-=lowbit(i)) {
		for(int j=y; j>0; j-=lowbit(j)) {
			ans += sum[i][j];
		}
	}
	return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i=1; i<=n; i++) {
            scanf("%s", str[i]+1);
			for(int j=1; j<=n; j++) {
				if(str[i][j] == '#') {
					update(i, j);
				}
			}
        }
        int res = 0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				for(int i1=i; i1<=n; i1++) {
					for(int j1=j; j1<=n; j1++) {
						int ans = query(i1, j1) - query(i-1, j1) - query(i1, j-1) + query(i-1, j-1);
						if(ans == 0)	res++;
						else	break;
					}
				}
			}
		}
		printf("%d\n", res);
    }
    return 0;
}

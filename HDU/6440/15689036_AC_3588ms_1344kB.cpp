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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const ll INF = 1e18+100;
const int maxn = 4e4+10;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;

int main() {
	scanf("%d", &T);
	while(T--) {
		int q;
		scanf("%d", &q);
		for(int i=0; i<q; i++) {
			for(int j=0; j<q; j++) {
				printf("%d%c", (i+j)%q, j==q-1 ? '\n' : ' ');
			}
		}
		for(int i=0; i<q; i++) {
			for(int j=0; j<q; j++) {
				printf("%d%c", i*j%q, j==q-1 ? '\n' : ' ');
			}
		}
	}
    return 0;
}

#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#include<queue>
#define lowbit(x)  (x&(-x))
const double eps=1e-8;
const int inf=0x3f3f3f3f;
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
#define ls rt<<1
#define rs rt<<1|1
#define m(i) (node[i].l+node[i].r)>>1

int n,m;

int main() {
    int a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ans = 0;
    int kongd = a;
    int kongs = b;
    int yous = 0;
    int x;
    for(int i=1; i<=n; i++) {
		scanf("%d", &x);
		if(x == 1) {
			if(kongd) {
				kongd --;
			} else {
				if(kongs) {
					kongs--;
					yous++;
				} else if(yous) {
					yous--;
				} else {
					ans++;
				}
			}
		} else if(x == 2) {
			if(kongs) {
				kongs--;
			} else {
				ans+=2;
			}
		}
    }
    cout << ans << endl;
    return 0;
}

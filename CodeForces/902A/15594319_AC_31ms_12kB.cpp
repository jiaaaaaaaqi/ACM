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
struct AA {
    int l,r;
} a[111];

bool cmp(AA a,AA b) {
	if(a.l == b.l)	return a.r < b.r;
    return a.l<b.l;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].l,&a[i].r);
        sort(a,a+n,cmp);
        if(a[0].l!=0) {
            printf("NO\n");
            continue;
        }
        int maxx=a[0].r;
        for(int i=1; i<n; i++) {
            if(a[i].l<=maxx) {
                maxx=max(maxx,a[i].r);
            }
        }
        if(maxx>=m) printf("YES\n");
        else printf("NO\n");

    }
}

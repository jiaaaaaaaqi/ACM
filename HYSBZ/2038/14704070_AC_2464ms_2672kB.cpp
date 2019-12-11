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
const int maxn = 50005;
const int maxm = 10000;
const int mod = 364875103;
using namespace std;

int n, m, tol;
int k, block;
struct Node {
    int l, r, id;
    bool operator < (Node a) const {
        return l/block == a.l/block ? r < a.r : l/block < a.l/block;
    }
};
struct Res {
    int a;
    int b;
};
Res res[maxn];
Node node[maxn];
int a[maxn];
int cnt[maxn];
int ans;

void init() {
    ans = 0;
    memset(cnt, 0, sizeof cnt);
    memset(node, 0, sizeof node);
    memset(res, 0, sizeof res);
    memset(a, 0, sizeof a);
}

int calc(int x) {
    return (x&1) ? (x-1)/2*x : x/2*(x-1);
}

void add(int x) {
    ans -= calc(cnt[a[x]]);
    cnt[a[x]]++;
    ans += calc(cnt[a[x]]);
}

void del(int x) {
    ans -= calc(cnt[a[x]]);
    cnt[a[x]]--;
    ans += calc(cnt[a[x]]);
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        block = sqrt(n);
        for(int i=1; i<=n; i++)	scanf("%d", &a[i]);
        for(int i=1; i<=m; i++) {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].id = i;
        }
        sort(node+1, node+1+m);
        int L = 1;
        int R = 0;
        for(int i=1; i<=m; i++) {
            while(L < node[i].l)
                del(L++);
            while(L > node[i].l)
                add(--L);
            while(R < node[i].r)
                add(++R);
            while(R > node[i].r)
                del(R--);
            res[node[i].id].a = ans;
            res[node[i].id].b = calc(node[i].r - node[i].l + 1);
            if(ans == 0) {
                res[node[i].id].a = 0;
                res[node[i].id].b = 1;
            } else {
                int x = gcd(res[node[i].id].a, res[node[i].id].b);
                res[node[i].id].a /= x;
                res[node[i].id].b /= x;
            }
        }
		for(int i=1; i<=m; i++) {
			printf("%d/%d\n", res[i].a, res[i].b);
		}
    }
    return 0;
}

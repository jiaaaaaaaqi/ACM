#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;
int a[maxn], b[maxn];
ull hash1[maxn], hash2[maxn];
ull nbase[maxn], seed = 131;

ull calc1(int l, int r) {
	return hash1[r] - hash1[l-1] * nbase[r-l+1];
}

ull calc2(int l, int r) {
	return hash2[r] - hash2[l-1] * nbase[r-l+1];
}

int solve(int L, int R) {
	int l = 1, r = min(n-L+1, m-R+1), ans = 0;
	while(l<=r) {
		int mid = (l+r) >> 1;
		ull h1 = calc1(L, L+mid-1);
		ull h2 = calc2(R, R+mid-1);
		if(h1 == h2)	l = mid+1, ans = mid;
		else	r = mid-1;
	}
	int p1 = L + ans;
	int p2 = R + ans;
//	printf("p1 = %d p2 = %d\n", p1, p2);
	if(a[p1] > b[p2])	return 1;
	else	return 2;
}

int main() {
    nbase[0] = 1;
    for(int i=1; i<=100000; i++) {
        nbase[i] = nbase[i-1]*seed;
    }
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        mes(a, 0);
        mes(b, 0);
        scanf("%d%d", &n, &m);
        hash1[0] = hash2[0] = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            hash1[i] = hash1[i-1]*seed + a[i];
        }
        for(int i=1; i<=m; i++) {
            scanf("%d", &b[i]);
            hash2[i] = hash2[i-1]*seed + b[i];
        }
		vector<int> ans;
		ans.clear();
        int l = 1, r = 1;
        while(l<=n && r<=m) {
            if(a[l] > b[r]) {
                ans.push_back(a[l]);
                l++;
            } else if(a[l] < b[r]) {
                ans.push_back(b[r]);
                r++;
            } else {
                int id = solve(l, r);
//                printf("id = %d\n", id);
                if(id == 1) {
                    ans.push_back(a[l]);
                    l++;
                } else {
                    ans.push_back(b[r]);
                    r++;
                }
            }
        }
		for(int i=l; i<=n; i++)	ans.push_back(a[i]);
		for(int i=r; i<=m; i++)	ans.push_back(b[i]);
		for(int i=1; i<=n+m; i++) {
			printf("%d", ans[i-1]);
		}
		printf("\n");

    }
	return 0;
}


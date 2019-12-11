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
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

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

int a[maxn];
int vis[maxn];
int Q1[maxn], Q2[maxn];

bool ok(int len) {
	int tail1 = 0, head1 = 0, tail2 = 0, head2 = 0;
    for(int i=1; i<=m; i++) {
        vis[i] = 0;
    }
    int cnt = 0;
    int ans = 0;
    for(int i=1; i<=len; i++) {
        if(a[i] != 0) {
			while (head1 < tail1 && a[i] > a[Q1[tail1-1]]) tail1--;
			Q1[tail1++] = i;
			
			while (head2 < tail2 && a[i] < a[Q2[tail2-1]]) tail2--;
			Q2[tail2++] = i;
			
            vis[a[i]]++;
            if(vis[a[i]] == 1)
                ans++;
        } else	cnt++;
    }
    int mx = a[Q1[head1]];
    int mn = a[Q2[head2]];
    
    if(head1 == tail1) {
        if(cnt == len)	return true;
    } else {
        if(mx-mn+1 <= ans+cnt && ans+cnt==len)	return true;
    }
    int l = 1, r = len;
    while(r < n) {
        r++;
        if(a[r] != 0) {
            vis[a[r]]++;
            if(vis[a[r]] == 1)
                ans++;
			while (head1 < tail1 && a[r] > a[Q1[tail1-1]]) tail1--;
			Q1[tail1++] = r;
			
			while (head2 < tail2 && a[r] < a[Q2[tail2-1]]) tail2--;
			Q2[tail2++] = r;
        } else {
            cnt++;
        }
        
        if(a[l] != 0) {
            vis[a[l]]--;
            if(vis[a[l]] == 0)
                ans--;
			while (head1 < tail1 && Q1[head1] < l+1) head1++;
			while (head2 < tail2 && Q2[head2] < l+1) head2++;
        } else {
            cnt--;
        }
		l++;
        
        mx = a[Q1[head1]];
        mn = a[Q2[head2]];
        
        if(head1 == tail1) {
            if(cnt == len)	return true;
        } else {
            if(mx-mn+1 <= ans+cnt && ans+cnt==len)	return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        int L = 1, R = n+1;
        while (L < R) {
            int mid = (L+R) / 2;
            if (ok(mid)) L = mid+1;
            else R = mid;
        }
        printf("%d\n", L-1);
    }
    return 0;
}


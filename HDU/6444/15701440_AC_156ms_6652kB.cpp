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
const int maxn = 1e5;
const int maxm = 1e9+10;
const int mod = 1e9+7;
using namespace std;

ll n, m;
int T, tol;
ll s, k;
bool vis[maxn];
ll a[maxn];
ll b[maxn];
ll sum[maxn];
vector<ll> vec[maxn];
struct Node{
	int first;
	ll second;
};
Node q[maxn];

void init() {
    tol = 0;
	memset(q, 0, sizeof q);
    for(int i=0; i<maxn; i++)	vec[i].clear();
    memset(vis, 0, sizeof vis);
}

ll solve(int op, int n, ll m) {
    ll ans = 0;
    memset(sum, 0, sizeof sum);
    for(int i=0; i<n; i++) 		sum[i] = i==0 ? vec[op][i] : sum[i-1] + vec[op][i];
    for(int i=n; i<2*n; i++) 	sum[i] = sum[i-1] + vec[op][i-n];
    for(int i=2*n; i<3*n; i++) 	sum[i] = sum[i-1] + vec[op][i-2*n];
    int head = 0;
    int tail = 0;
    for(int i=0; i<3*n; i++) {
        while(head < tail && q[tail-1].second > sum[i-1])	tail--;
        while(head < tail && q[head].first + m < i)			head++;
        q[tail].first = i-1;
        q[tail].second = sum[i-1];
        tail++;
        if(ans < sum[i] - q[head].second) {
            ans = sum[i] - q[head].second;
        }
    }
    return ans;
}

int main() {
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%lld%lld%lld%lld", &n, &s, &m, &k);
        for(int i=0; i<n; i++)	scanf("%lld", &a[i]);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int pos = i;
                while(!vis[pos]) {
                    vis[pos] = 1;
                    vec[tol].push_back(a[pos]);
                    pos = (pos + k) % n;
                }
                tol++;
            }
        }
//        for(int i=0; i<tol; i++)	for(int j=0; j<vec[i].size(); j++)	printf("%lld%c", vec[i][j], j==vec[i].size()-1 ? '\n' : ' ');
        ll ans = -inf;
        for(int i=0; i<tol; i++) {
			ll res = -inf;
			int len = vec[i].size();
			ll tmp = 0;
			for(int j=0; j<len; j++)	tmp += vec[i][j];
			res = solve(i, len, m);	
			ans = max(ans, res);
			if(tmp < 0)	continue;
			ll x = m % len;
			ll y = m / len;
			tmp = max(y-1, 0ll) * tmp;
			if(y >= 1)	x += len;
			res = max(res, solve(i, len, x) + tmp);
			ans = max(ans, res);
        }
        ans = max(0ll, s-ans);
        printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}

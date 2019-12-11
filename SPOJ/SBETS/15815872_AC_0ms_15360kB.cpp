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
const int    maxn = 10005;
const int    maxm = 1<<10;
const int    mod  = 1000000007;
const ll     INF  = 1e18+100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0*atan(1.0);
using namespace std;

int n, m;
int T, tol, in[maxn];
map <string, int> mp;
int main() {
	scanf("%d", &T);
	string str1, str2;
	int u, v, g1, g2;
	while (T--) {
		mp.clear();
		memset(in, 0, sizeof in);
		int cnt = 1;
		for (int i = 1; i <= 16; i++) {
			cin >> str1 >> str2 >> g1 >> g2;
			if(mp[str1] == 0)	mp[str1] = cnt++;
			if(mp[str2] == 0)	mp[str2] = cnt++;
			u = mp[str1];
			v = mp[str2];
			if (g1 > g2) in[v]++;
			else in[u]++;
		}
		int ans;
		for (int i = 1; i <= cnt; i++) {
			if (in[i] == 0) {
				ans = i;
				break;
			}
		}
		for (auto i: mp) {
			if (i.second == ans) {
				cout << i.first << endl;
				break;
			}
		}
	}
	return 0;
}

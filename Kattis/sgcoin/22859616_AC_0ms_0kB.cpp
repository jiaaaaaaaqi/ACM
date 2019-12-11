/*************************************************************** 
	> File Name		: C.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Wed 13 Nov 2019 11:16:38 PM CST
 ***************************************************************/

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
#include <unordered_map>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
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

ll n, m;
int cas, tol, T;


ll ans[200] = {19999685, 9999699, 9999713, 9999727, 9999741, 9999755, 9999776, 9999790, 9999804, 9999818, 9999832, 9999846, 9999867, 9999881, 9999895, 9999909, 9999923, 9999937, 9999958, 9999972, 9999986, 0, 14, 28, 49, 63, 77, 91, 105, 119, 140, 154, 168, 182, 196, 210, 231, 245, 259, 273, 287, 301, 322, 336, 350, 364, 378, 392, 413, 427, 441, 455, 469, 10000490, 504, 518, 532, 546, 560, 581, 595, 609, 623, 637, 651, 672, 686, 700, 714, 728, 742, 763, 777, 791, 805, 819, 833, 854, 868, 882, 896, 910, 924, 945, 959, 973, 987, 1001, 1015, 1036, 1050, 1064, 1078, 1092, 1106, 1127, 1141, 1155, 1169, 1183, 1197, 1218, 1232, 1246, 1260, 1274, 1295, 1309, 1323, 1337, 1351};

long long H(long long previousHash, string &transaction, long long token) {
	long long v = previousHash;
	for (int i = 0; i < transaction.length(); i++) {
		v = (v * 31 + transaction[i]) % 1000000007;
	}
	return (v * 7 + token) % 1000000007;
}

void handle() {
	for(int i=0; i<=0; i++) {
		ll x = 1ll*i*m;
		x = x*31+'-';
		x %= mod;
		for(int j=0; ; j++) {
			ll p = x*7ll+j;
			p %= mod;
			if(p%10000000 == 0) {
				ans[i] = j;
				break;
			}
		}
	}
}

int main() {
	// freopen("in", "r", stdin);
	// handle();
	m = 10000000;
	scanf("%lld", &n);	
	// {
	//     ll a = n, c = ans[n/m];
	//     string b = "-";
	//     if(H(a, b, c)%m != 0)	cout << "!!!" << endl;
	// }
	printf("- %lld\n", ans[n/m]);
	ll x = n*31ll+'-';
	x %= mod;
	x = x*7ll+ans[n/m];
	n = x%mod;
	// {
	//     ll a = n, c = ans[n/m];
	//     string b = "-";
	//     if(H(a, b, c)%m != 0)	cout << "!!!" << endl;
	// }
	printf("- %lld\n", ans[n/m]);
	return 0;
}

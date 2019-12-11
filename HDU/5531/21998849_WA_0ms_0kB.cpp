/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 30 Sep 2019 09:01:35 PM CST
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

int n, m;
int cas, tol, T;

struct Node {
	int x, y;
} node[maxn];
double res[maxn];

double dis(Node a, Node b) {
	ll ans = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return sqrt(1.0*ans);
}

double calc(double r1) {
	double ans = 0;
	res[1] = r1;
	ans += r1*r1;
	for(int i=2; i<=n; i++) {
		res[i] = dis(node[i], node[i-1]) - res[i-1];
		ans += res[i]*res[i];
	}
	for(int i=1; i<n; i++) {
		if(res[i]<0 || res[i]>dis(node[i], node[i+1]) || res[i]>dis(node[i], node[i==1 ? n:i-1]))
			return -1.0;
	}
	return ans*pi;
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d%d", &node[i].x, &node[i].y);
		}
		double tmp = 0;
		for(int i=1; i<n; i++) {
			if(i&1)	tmp += dis(node[i], node[i+1]);
			else	tmp -= dis(node[i], node[i+1]);
		}
		tmp += dis(node[1], node[n]);
		if(n&1) {
			if(tmp<0)	printf("IMPOSSIBLE\n");
			else {
				double area = calc(tmp/2.0);
				if(area<0) {
					printf("IMPOSSIBLE\n");
				} else {
					printf("%.2f\n", area);
					for(int i=1; i<=n; i++) {
						printf("%.2f\n", res[i]);
					}
				}
			}
		} else {
			if(tmp < 0)	printf("IMPOSSIBLE\n");
			else {
				double l = 0, r = tmp/2.0;			
				while(fabs(l-r) >= eps) {
					double lmid = l+(r-l)/3.0, rmid = r-(r-l)/3.0;
					double area1 = calc(lmid);
					double area2 = calc(rmid);
					if(area1 < area2)	r = rmid;
					else	l = lmid;
				}
				double area = calc(l);
				if(area<0) {
					printf("IMPOSSIBLE\n");
				} else {
					printf("%.2f\n", area);
					for(int i=1; i<=n; i++)	printf("%.2f\n", res[i]);
				}
			}
		}
	}
	return 0;
}


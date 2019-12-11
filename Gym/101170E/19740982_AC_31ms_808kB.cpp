/***************************************************************
    > File Name    : E.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年05月14日 星期二 22时12分39秒
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

struct Node{
	int a, id;
	bool operator < (Node s) const {
		return a > s.a;
	}
} node[maxn];

int main() {
	scanf("%d", &n);
	int sum = 0;
	for(int i=1; i<=n; i++) {
		scanf("%d", &node[i].a);
		sum += node[i].a;
		node[i].id = i;
	}
	sort(node+1, node+1+n);
	if(2*node[1].a > sum) {
		printf("impossible\n");
	} else {
		for(int i=1; i<=n; i++) {
			printf("%d%c", node[i].id, i==n ? '\n' : ' ');
		}
	}
	return 0;
}


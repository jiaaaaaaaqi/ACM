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
double x1, y1, r1;
double x2, y2, r2;

double calc() {
	double x = fabs(x1-x2);
	double y = fabs(y1-y2);
	return sqrt(x*x + y*y);
}

int solve(double dis, double r1, double r2) {
	if(dis > (r1+r2))	return 5;
	if(fabs(dis-r1-r2) <= eps)	return 4;
	if(fabs(r1-r2) < dis && dis < fabs(r1+r2))	return 3;
	if(fabs(dis-(fabs(r1-r2))) <= eps)	return 2;
	return 1;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double dis = calc();
		int flag = solve(dis, r1, r2);
		printf("%d\n", flag-1);
	}
	return 0;
}

/*************************************************************** 
	> File Name		: A.cpp
	> Author		: Jiaaaaaaaqi
	> Created Time	: Thu 14 Nov 2019 01:31:48 PM CST
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

int a[30];
stack<int> sta;

int solve(int x, int y, char ch) {
	if(ch == '*') {
		if(x==1 && y==1)	return 1;
		return 0;
	} else {
		if(x==0 && y==0)	return 0;
		return 1;
	}
}

int main() {
	// freopen("in", "r", stdin);
	scanf("%d", &n);
	while(!sta.empty())	sta.pop();
	char s[50];
	for(int i=1; i<=n; i++) {
		scanf("%s", s+1);
		a[i] = s[1]=='T' ? 1 : 0;
	}
	while(~scanf("%s", s+1)) {
		if(s[1]>='A' && s[1]<='Z')	sta.push(a[s[1]-'A'+1]);
		else {
			if(s[1] == '-') {
				int x = sta.top();
				sta.pop();
				sta.push(!x);
			} else {
				int x, y;
				x = sta.top(), sta.pop();
				y = sta.top(), sta.pop();
				sta.push(solve(x, y, s[1]));
			}
		}
	}
	if(sta.top() == 1)	printf("T\n");
	else	printf("F\n");
	return 0;
}


/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年08月16日 星期五 11时05分51秒
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
 
char s[10];
 
int calc(int d[]) {
	int ans = 0;
	if(d[1] != s[1]-'0')	ans++;
	if(d[2] != s[2]-'0')	ans++;
	if(d[3] != s[3]-'0')	ans++;
	if(d[4] != s[4]-'0')	ans++;
	if(d[5] != s[5]-'0')	ans++;
	if(d[6] != s[6]-'0')	ans++;
	return ans;
}
 
int main() {
	// freopen("in", "r", stdin);
	scanf("%s", s+1);
	int ans = 10;
	int d[10] = {0};
	for(d[1]=0; d[1]<=9; d[1]++) {
		for(d[2]=0; d[2]<=9; d[2]++) {
			for(d[3]=0; d[3]<=9; d[3]++) {
				for(d[4]=0; d[4]<=9; d[4]++) {
					for(d[5]=0; d[5]<=9; d[5]++) {
						for(d[6]=0; d[6]<=9; d[6]++) {
							if(d[1]+d[2]+d[3] == d[4]+d[5]+d[6])	ans = min(ans, calc(d));
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
 
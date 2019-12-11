/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月08日 星期一 18时05分07秒
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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[maxn];

int main() {
	while(~scanf("%s", s+1)) {
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			if(s[i]=='A' && s[i+1]=='p' && s[i+2]=='p' && s[i+3]=='l' && s[i+4]=='e')
				printf("MAI MAI MAI!\n");
			if(s[i]=='i' && s[i+1]=='P' && s[i+2]=='h' && s[i+3]=='o' && s[i+4]=='n' && s[i+5]=='e')
				printf("MAI MAI MAI!\n");
			if(s[i]=='i' && s[i+1]=='P' && s[i+2]=='o' && s[i+3]=='d')
				printf("MAI MAI MAI!\n");
			if(s[i]=='i' && s[i+1]=='P' && s[i+2]=='a' && s[i+3]=='d')
				printf("MAI MAI MAI!\n");
			if(s[i]=='S' && s[i+1]=='o' && s[i+2]=='n' && s[i+3]=='y')
				printf("SONY DAFA IS GOOD!\n");
		}
		mes(s, 0);
	}
	return 0;
}


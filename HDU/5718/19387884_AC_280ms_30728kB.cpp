/***************************************************************
    > File Name    : b.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年04月21日 星期日 18时58分23秒
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
const int    maxn = 1e7 + 10;
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
char s1[maxn], s2[maxn];
int cnt[10];

int main() {
	scanf("%d", &T);
	while(T--) {
		mes(cnt, 0);
		mes(s, 0);
		mes(s1, 0);
		mes(s2, 0);
		scanf("%s", s+1);
		int len = strlen(s+1);
		if(len == 1) {
			printf("Uncertain\n");
			continue;
		} else {
			for(int i=1; i<=len; i++) {
				cnt[s[i]-'0']++;
			}
			bool flag = false;
			for(int i=1; i<=9; i++) {
				if(cnt[i]) {
					s2[1] = i+'0';
					cnt[i]--;
					break;
				}
			}
			int l1 = 0;
			for(int i=9; i>=0; i--) {
				if(i && cnt[i])	flag = true;
				for(int j=1; j<=cnt[i]; j++)
					s1[++l1] = i+'0';
			}
			if(flag == 0) {
				printf("Uncertain\n");
				continue;
			} else {
				s1[l1] += s2[1]-'0';
				for(int i=l1; i>=1; i--) {
					if(s1[i]-'0' >= 10) {
						s1[i] -= 10;
						if(i != 1)
							s1[i-1]++;
						else
							s1[0] = '1';
					}
				}
				if(s1[0]) {
					printf("%s\n", s1);
				} else {
					printf("%s\n", s1+1);
				}
			}
		}
	}
	return 0;
}


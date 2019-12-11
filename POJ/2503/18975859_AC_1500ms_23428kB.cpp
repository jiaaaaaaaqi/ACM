/***************************************************************
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : 2019年03月28日 星期四 22时45分56秒
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

const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s[105], s2[105];
char s1[maxn][105];
struct Node {
	int next[26];
	int id;
	void init() {
		mes(next, 0);
		id = 0;
	}
} node[maxn*100];

void init() {
	tol = 0;
	node[tol].init();
}

void insert(char *s, int id) {
	int len = strlen(s+1);
	int rt = 0;
	for(int i=1, k; i<=len; i++) {
		k = s[i] - 'a';
		if(node[rt].next[k] == 0) {
			node[++tol].init();
			node[rt].next[k] = tol;
		}
		rt = node[rt].next[k];
	}
	node[rt].id = id;
}

int query(char *s) {
	int len = strlen(s+1);
	int rt = 0;
	for(int i=1, k; i<=len; i++) {
		k = s[i] - 'a';
		if(node[rt].next[k] == 0)	return -1;
		rt = node[rt].next[k];
	}
	return node[rt].id;
}

int main() {
	init();
	int id = 0;
	while(cin.getline(s, 105)) {
		if(s[0] == '\0')	break;
		sscanf(s, "%s%s", s1[++id]+1, s2+1);		
		insert(s2, id);
	}
	while(~scanf("%s", s2+1)) {
		int id = query(s2);
		if(id == -1)	printf("eh\n");
		else	printf("%s\n", s1[id]+1);
	}
	return 0;
}


/*************************************************************** 
    > File Name    : a.cpp
    > Author       : Jiaaaaaaaqi
    > Created Time : Mon 29 Jul 2019 09:59:42 PM CST
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
const int    maxn = 3e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct pTree {
    int Next[maxn][27];
    int fail[maxn];
    ll cnt[maxn];
    ll sum[maxn];
    int num[maxn];
    int len[maxn];
    int pos[maxn];
    int S[maxn];
    int last, n, p, cur, now;

    int newnode(int l) {
        for (int i=1; i<=26; i++) Next[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init() {
        n = p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        S[n] = -1;
        fail[0] = 1;
    }

    int getFail(int x) {
        while (S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }

    bool insert(int c, int id) {
        S[++n] = c;
        cur = getFail(last);
        bool flag = false;
        if (!Next[cur][c]) {
            flag = true;
            now = newnode(len[cur] + 2);
            fail[now] = Next[getFail(fail[cur])][c];
            Next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = Next[cur][c];
        pos[last] = id;
        cnt[last]++;
        return flag;
    }
    void count() {
        for (int i = p-1; i >= 0; i--) cnt[fail[i]] += cnt[i];
    }
}tree;
char s[maxn];
int ans[maxn];
ull seed = 131;
ull hash1[maxn], hash2[maxn], base[maxn];

ull gethash1(int l, int r) {
	return hash1[r] - hash1[l-1]*base[r-l+1];
}

ull gethash2(int l, int r) {
	return hash2[l] - hash2[r+1]*base[r-l+1];
}

int main() {
	// freopen("in", "r", stdin);
	base[0] = 1;
	for(int i=1; i<=300000; i++) {
		base[i] = base[i-1]*seed;
	}
	while(~scanf("%s", s+1)) {
		tree.init();
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			tree.insert(s[i]-'a'+1, i);
		}
		tree.count();
		hash1[0] = 0;
		for(int i=1; i<=len; i++) {
			hash1[i] = hash1[i-1]*seed + s[i];
		}
		hash2[len+1] = 0;
		for(int i=len; i>=1; i--) {
			hash2[i] = hash2[i+1]*seed + s[i];
		}
		mes(ans, 0);
		for(int i=2; i<tree.p; i++) {
			int r = tree.pos[i];
			int l = r-tree.len[i]+1;
			int mid = l+r>>1;
			if(gethash1(l, mid) == gethash2(l, mid))
				ans[tree.len[i]] += tree.cnt[i];
		}
		for(int i=1; i<=len; i++) {
			printf("%d%c", ans[i], i==len ? '\n' : ' ');
		}
	}
	return 0;
}


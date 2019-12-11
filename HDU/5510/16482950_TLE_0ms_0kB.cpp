#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <bitset>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 5e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Trie {
	int next[maxn][26], fail[maxn], next1[maxn][26];
	bitset <505> end[maxn];
	bitset <505> one[505];
	int root, sz;
	int newnode() {
		for (int i = 0; i < 26; i++) {
			next[sz][i] = -1;
		}
		end[sz++].reset();
		return sz-1;
	}
	void init() {
		sz = 0;
		root = newnode();
		one[0][0] = 1;
		for(int i=1; i<=500; i++)
			one[i] = one[i-1] << 1;
 	}
	void insert(char buf[], int id) {
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++) {
			if (next[now][buf[i]-'a'] == -1)
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now] |= one[id];
	}

	void build() {
		for(int i=0; i<=sz; i++) {
			for(int j=0; j<26; j++) {
				next1[i][j] = next[i][j];
			}
		}
		queue <int> Q;
		fail[root] = root;
		for (int i = 0; i < 26; i++) {
			if (next1[root][i] == -1)
				next1[root][i] = root;
			else {
				fail[next1[root][i]] = root;
				Q.push(next1[root][i]);
			}
		}
		while (!Q.empty()) {
			int now = Q.front();
			end[now] |= end[fail[now]];
			Q.pop();
			for (int i = 0; i < 26; i++) {
				if (next1[now][i] == -1)
					next1[now][i] = next1[fail[now]][i];
				else {
					fail[next1[now][i]] = next1[fail[now]][i];
					Q.push(next1[now][i]);
				}
			}
		}
	}
	int query(char buf[]) {
		int len = strlen(buf);
		int now = root;
		bitset <505> res;
		for (int i = 0; i < len; i++) {
			now = next1[now][buf[i]-'a'];
			int temp = now;
			while (temp != root) {
				res |= end[temp];
				//printf("%d\n", res);
				//end[temp] = 0;
				temp = fail[temp];
			}
		}
		return res.count();
	}
}AC;

int main() {
	int kase = 0;
    scanf("%d", &T);
    char word[2005];
    while (T--) {
		scanf("%d", &n);
		AC.init();
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			scanf("%s", word);
			AC.build();
			//printf("query = %d\n", AC.query(word));
			//if (AC.query(word) != i-1) flag = 1, ans = i;
			int cnt = AC.query(word);
			//printf("cnt = %d\n", cnt);
			if (cnt != i-1) ans = i;
			AC.insert(word, i-1);
		}
		printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}

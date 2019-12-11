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
	int next[maxn][26], fail[maxn], end[maxn], count[maxn];
	int root, sz;
	int newnode() {
		for (int i = 0; i < 26; i++) {
			next[sz][i] = -1;
		}
		end[sz] = 0;
		count[sz++] = 0;
		return sz-1;
	}
	void init() {
		sz = 0;
		root = newnode();
 	}
	void insert(char buf[], int id) {
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; i++) {
			if (next[now][buf[i]-'a'] == -1)
				next[now][buf[i]-'a'] = newnode();
			now = next[now][buf[i]-'a'];
		}
		end[now] = id;
		count[now]++;
	}
	void build() {
		queue <int> Q;
		fail[root] = root;
		for (int i = 0; i < 26; i++) {
			if (next[root][i] == -1)
				next[root][i] = root;
			else {
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}
		while (!Q.empty()) {
			int now = Q.front();
			Q.pop();
			for (int i = 0; i < 26; i++) {
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else {
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
	int cnt[maxn];
	int query(char buf[], int id) {
		for(int i=0; i<maxn; i++)
			cnt[i] = count[i];
		int len = strlen(buf);
		int now = root;
		int res = 0;
		for (int i = 0; i < len; i++) {
			now = next[now][buf[i]-'a'];
			int temp = now;
			while (temp != root) {
				if (end[temp] <= id && end[temp] != 0) {
					res += cnt[temp];
				}
				cnt[temp] = 0;
				temp = fail[temp];
			}
		}
		return res;
	}
}AC;
char word[505][2005];

int main() {
	int kase = 0;
    scanf("%d", &T);
    while (T--) {
		mes(word, 0);
		scanf("%d", &n);
		AC.init();
		for (int i = 1; i <= n; i++) {
			scanf("%s", word[i]);
			AC.insert(word[i], i);			
		}
		AC.build();
		int ans = -1;
		for(int i=n; i>=1; i--) {
			int cnt = AC.query(word[i], i);
			printf("%d %d\n", i, cnt);
			if(cnt != i) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}

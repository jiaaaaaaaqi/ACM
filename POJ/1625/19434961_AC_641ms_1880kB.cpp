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

int n, m, p;
int cas, tol, T;

struct BigInteger {
    int A[25];
    enum {MOD = 10000};
    BigInteger() {
        memset(A, 0, sizeof(A));
        A[0]=1;
    }
    void set(int x) {
        memset(A, 0, sizeof(A));
        A[0]=1;
        A[1]=x;
    }
    void print() {
        printf("%d", A[A[0]]);
        for (int i=A[0]-1; i>0; i--) {
            if (A[i]==0) {
                printf("0000");
                continue;
            }
            for (int k=10; k*A[i]<MOD; k*=10) printf("0");
            printf("%d", A[i]);
        }
        printf("\n");
    }
    int& operator [] (int p) {
        return A[p];
    }
    const int& operator [] (int p) const {
        return A[p];
    }
    BigInteger operator + (const BigInteger& B) {
        BigInteger C;
        C[0]=max(A[0], B[0]);
        for (int i=1; i<=C[0]; i++)
            C[i]+=A[i]+B[i], C[i+1]+=C[i]/MOD, C[i]%=MOD;
        if (C[C[0]+1] > 0) C[0]++;
        return C;
    }
    BigInteger operator * (const BigInteger& B) {
        BigInteger C;
        C[0]=A[0]+B[0];
        for (int i=1; i<=A[0]; i++)
            for (int j=1; j<=B[0]; j++) {
                C[i+j-1]+=A[i]*B[j], C[i+j]+=C[i+j-1]/MOD, C[i+j-1]%=MOD;
            }
        if (C[C[0]] == 0) C[0]--;
        return C;
    }
} dp[2][300];
struct Mat {
	int sz;
	BigInteger mat[110][110];
};
struct AC {
	int node[300][55], cnt[300], fail[300];
	int root, sz;
	int newnode() {
		mes(node[sz], -1);
		cnt[sz++] = 0;
		return sz-1;
	}
	void init() {
		sz = 0;
		root = newnode();
	}
	void insert(int s[], int len) {
		int rt = root;
		for(int i=1; i<=len; i++) {
			int k = s[i];
			if(node[rt][k] == -1) {
				node[rt][k] = newnode();
			}
			rt = node[rt][k];
		}
		cnt[rt] = 1;
	}
	void build() {
		queue<int> q;
		while(!q.empty())	q.pop();
		for(int i=1; i<=n; i++) {
			if(node[root][i] == -1) {
				node[root][i] = root;
			} else {
				fail[node[root][i]] = root;
				q.push(node[root][i]);
			}
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(cnt[fail[u]])
				cnt[u] = 1;
			for(int i=1; i<=n; i++) {
				if(node[u][i] == -1) {
					node[u][i] = node[fail[u]][i];
				} else {
					fail[node[u][i]] = node[fail[u]][i];
					q.push(node[u][i]);
				}
			}
		}
	}
} ac;
int s[200];
char t[200];
map<char, int> mp;
int main() {
	mp.clear();
	scanf("%d%d%d", &n, &m, &p);
	getchar();
	gets(t+1);
//	printf("%s\n", t+1);
	int len = strlen(t+1);
	for(int i=1; i<=len; i++) {
		mp[t[i]] = i;
	}
	ac.init();
	for(int i=1; i<=p; i++) {
		gets(t+1);
		len = strlen(t+1);
//		printf("%s\n", t+1);
		for(int i=1; i<=len; i++) {
			s[i] = mp[t[i]];
		}
		ac.insert(s, len);
	}
	ac.build();
	Mat a;
	BigInteger one, ans;
	a.sz = ac.sz;
	one.set(1);
	for(int i=0; i<ac.sz; i++) {
		if(ac.cnt[i])	continue;
		for(int j=1; j<=n; j++) {
			int k = ac.node[i][j];
			if(ac.cnt[k])	continue;
			a.mat[i+1][k+1] = a.mat[i+1][k+1] + one;
		}
	}
	dp[1][1].set(1);
	for(int i=2; i<=a.sz; i++) {
		dp[1][i].set(0);
	}
	int flag = 1;
	for(int i=1; i<=m; i++) {
		flag = !flag;
		for(int j=1; j<=a.sz; j++) {
			dp[flag][j].set(0);
		}
		for(int j=1; j<=a.sz; j++) {
			for(int k=1; k<=a.sz; k++) {
				dp[flag][k] = dp[flag][k] + dp[!flag][j]*a.mat[j][k];
			}
		}
	}
	ans.set(0);
	for(int i=1; i<=a.sz; i++) {
		ans = ans + dp[flag][i];
	}
	ans.print();
	return 0;
}

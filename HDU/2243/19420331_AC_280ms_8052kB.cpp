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

struct AC {
    int next[50][27], fail[50], cnt[50];
    int root, sz;
    int newnode() {
        mes(next[sz], -1);
        cnt[sz++] = 0;
        return sz-1;
    }
    void init() {
        sz = 0;
        root = newnode();
    }
    void insert(char *s) {
        int len = strlen(s+1);
        int rt = root;
        for(int i=1; i<=len; i++) {
            int k = s[i]-'a'+1;
            if(next[rt][k] == -1) {
                next[rt][k] = newnode();
            }
            rt = next[rt][k];
        }
        cnt[rt] = 1;
    }
    void build() {
        queue<int> q;
        while(!q.empty())	q.pop();
        fail[root] = root;
        for(int i=1; i<=26; i++) {
            if(next[root][i] == -1) {
                next[root][i] = root;
            } else {
                fail[next[root][i]] = root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(cnt[fail[u]])
                cnt[u] = 1;
            for(int i=1; i<=26; i++) {
                if(next[u][i] == -1) {
                    next[u][i] = next[fail[u]][i];
                } else {
                    fail[next[u][i]] = next[fail[u]][i];
                    q.push(next[u][i]);
                }
            }
        }
    }
} ac;

struct Mat {
    int sz;
    ull mat[40][40];
    void init() {
        mes(mat, 0);
    }
};
char s[10];

Mat mmul(Mat A, Mat B) {
	Mat ans;
	ans.sz = A.sz;
	ans.init();
	for(int i=1; i<=A.sz; i++) {
		for(int j=1; j<=A.sz; j++) {
			for(int k=1; k<=A.sz; k++) {
				ans.mat[i][j] += A.mat[i][k]*B.mat[k][j];
			}
		}
	}
	return ans;
}

Mat madd(Mat A, Mat B) {
	Mat ans;
	ans.sz = A.sz;
	ans.init();
	for(int i=1; i<=A.sz; i++) {
		for(int j=1; j<=A.sz; j++) {
			ans.mat[i][j] = A.mat[i][j]+B.mat[i][j];
		}
	}
	return ans;
}

Mat mpow(Mat A, int b) {
	Mat ans;
	ans.sz = A.sz;
	ans.init();
	for(int i=1; i<=ans.sz; i++) {
		ans.mat[i][i] = 1;
	}
	while(b) {
		if(b&1)	ans = mmul(ans, A);
		A = mmul(A, A);
		b >>= 1;
	}
	return ans;
}

Mat work(Mat A, int n) {
	if(n == 1)	return A;
	if(n%2 == 0) {
		Mat ans;
		ans.sz = A.sz;
		ans = work(A, n/2);
		return madd(mmul(ans, mpow(A, n/2)), ans);
	} else {
		n--;
		Mat ans;
		ans.sz = A.sz;
		ans = work(A, n/2);
		return madd(madd(mmul(ans, mpow(A, n/2)), ans), mpow(A, n+1));
	}
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        ac.init();
        for(int i=1; i<=n; i++) {
            scanf("%s", s+1);
            ac.insert(s);
        }
        ac.build();
        Mat tn, sn;
        sn.sz = tn.sz = ac.sz;
        tn.init();
        sn.init();
        for(int i=0; i<ac.sz; i++) {
            for(int j=1; j<=26; j++) {
                int k = ac.next[i][j];
                sn.mat[i+1][k+1]++;
            }
            if(ac.cnt[i])	continue;
            for(int j=1; j<=26; j++) {
                int k = ac.next[i][j];
                if(ac.cnt[k])	continue;
                tn.mat[i+1][k+1]++;
            }
        }
//        for(int i=1; i<=sn.sz; i++) {
//            for(int j=1; j<=sn.sz; j++) {
//                printf("%llu%c", sn.mat[i][j], j==sn.sz ? '\n' : ' ');
//            }
//        }
//        for(int i=1; i<=tn.sz; i++) {
//            for(int j=1; j<=tn.sz; j++) {
//                printf("%llu%c", tn.mat[i][j], j==tn.sz ? '\n' : ' ');
//            }
//        }
		Mat Sn = work(sn, m);
		Mat Tn = work(tn, m);
//		printf("\n");
//        for(int i=1; i<=Sn.sz; i++) {
//            for(int j=1; j<=Sn.sz; j++) {
//                printf("%llu%c", Sn.mat[i][j], j==Sn.sz ? '\n' : ' ');
//            }
//        }
//        for(int i=1; i<=tn.sz; i++) {
//            for(int j=1; j<=tn.sz; j++) {
//                printf("%llu%c", tn.mat[i][j], j==tn.sz ? '\n' : ' ');
//            }
//        }
		ull ans = 0;
		for(int i=1; i<=Sn.sz; i++)	ans += Sn.mat[1][i];
//		cout << ans << endl;
		for(int i=1; i<=Tn.sz; i++)	ans -= Tn.mat[1][i];
		printf("%I64u\n", ans);
    }
    return 0;
}

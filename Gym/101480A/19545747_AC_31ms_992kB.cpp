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

string digit[20][10];
string ss[10];
char s[10][maxn];
int a[10];

int solve() {
	for(int i=0; i<=10; i++) {
		int cnt = 0;
		for(int j=1; j<=7; j++) {
			if(ss[j] == digit[i][j])
				cnt++;
		}
		if(cnt == 7)	return i;
	}
}

int main() {
	digit[0][1] = "xxxxx";
	digit[0][2] = "x...x";
	digit[0][3] = "x...x";
	digit[0][4] = "x...x";
	digit[0][5] = "x...x";
	digit[0][6] = "x...x";
	digit[0][7] = "xxxxx";
		
	digit[1][1] = "....x";
	digit[1][2] = "....x";
	digit[1][3] = "....x";
	digit[1][4] = "....x";
	digit[1][5] = "....x";
	digit[1][6] = "....x";
	digit[1][7] = "....x";

	digit[2][1] = "xxxxx";
	digit[2][2] = "....x";
	digit[2][3] = "....x";
	digit[2][4] = "xxxxx";
	digit[2][5] = "x....";
	digit[2][6] = "x....";
	digit[2][7] = "xxxxx";
	
	digit[3][1] = "xxxxx";
	digit[3][2] = "....x";
	digit[3][3] = "....x";
	digit[3][4] = "xxxxx";
	digit[3][5] = "....x";
	digit[3][6] = "....x";
	digit[3][7] = "xxxxx";

	digit[4][1] = "x...x";
	digit[4][2] = "x...x";
	digit[4][3] = "x...x";
	digit[4][4] = "xxxxx";
	digit[4][5] = "....x";
	digit[4][6] = "....x";
	digit[4][7] = "....x";

	digit[5][1] = "xxxxx";
	digit[5][2] = "x....";
	digit[5][3] = "x....";
	digit[5][4] = "xxxxx";
	digit[5][5] = "....x";
	digit[5][6] = "....x";
	digit[5][7] = "xxxxx";

	digit[6][1] = "xxxxx";
	digit[6][2] = "x....";
	digit[6][3] = "x....";
	digit[6][4] = "xxxxx";
	digit[6][5] = "x...x";
	digit[6][6] = "x...x";
	digit[6][7] = "xxxxx";

	digit[7][1] = "xxxxx";
	digit[7][2] = "....x";
	digit[7][3] = "....x";
	digit[7][4] = "....x";
	digit[7][5] = "....x";
	digit[7][6] = "....x";
	digit[7][7] = "....x";
	
	digit[8][1] = "xxxxx";
	digit[8][2] = "x...x";
	digit[8][3] = "x...x";
	digit[8][4] = "xxxxx";
	digit[8][5] = "x...x";
	digit[8][6] = "x...x";
	digit[8][7] = "xxxxx";
	
	digit[9][1] = "xxxxx";
	digit[9][2] = "x...x";
	digit[9][3] = "x...x";
	digit[9][4] = "xxxxx";
	digit[9][5] = "....x";
	digit[9][6] = "....x";
	digit[9][7] = "xxxxx";

	digit[10][1] = ".....";
	digit[10][2] = "..x..";
	digit[10][3] = "..x..";
	digit[10][4] = "xxxxx";
	digit[10][5] = "..x..";
	digit[10][6] = "..x..";
	digit[10][7] = ".....";

	for(int i=1; i<=7; i++) {
		scanf("%s", s[i]+1);
	}
	int len = strlen(s[1]+1);
	int all = (len+1)/6;
	for(int i=1; i<=all; i++) {
		for(int j=1; j<=7; j++) {
			ss[j] = "";
			int st = 6*(i-1);
			for(int k=1; k<=5; k++) {
				ss[j] = ss[j]+s[j][st+k];
			}
		}
		a[i] = solve();
	}
	ll ans1, ans2;
	bool flag;
	ans1 = ans2 = flag = 0;
	for(int i=1; i<=all; i++) {
		if(a[i] == 10) {
			flag = true;
			continue;
		}
		if(flag) {
			ans2 = ans2*10+a[i];
		} else {
			ans1 = ans1*10+a[i];
		}
	}
	int ans = ans1+ans2;
	mes(a, 0);
	len = log10(1.0*ans)+1;
	for(int i=len; i>=1; i--) {
		a[i] = ans%10;
		ans /= 10;
	}
	for(int j=1; j<=7; j++) {
		for(int i=1; i<=len; i++) {
			int d = a[i];
			cout << digit[d][j];
			if(i!=len)
				cout << ".";
			else
				cout << "\n";
		}
	}
	return 0;
}

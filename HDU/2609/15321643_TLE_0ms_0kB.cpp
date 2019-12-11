#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 105;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
char s1[maxn];
set<string> se;

int min_express(char *s) {
	int i = 0, j = 1, k = 0;
	while(i<n && j<n && k<n) {
		int t = s[(i+k)%n] - s[(j+k)%n];
		if(t == 0)	k++;
		else {
			if(t > 0)	i += k+1;
			if(t < 0)	j += k+1;
			if(i == j)	j++;
			k = 0;
		}
	}
	return min(i, j);
}

int main() {
	while(~scanf("%d", &n)) {
		se.clear();
		for(int i=1; i<=n; i++) {
			scanf("%s", s);
			int len = strlen(s);
			int pos = min_express(s);
			for(int i=0; i<len; i++) {
				s1[i] = s[pos];
				pos = (pos+1) % len;
			}
			string s2(s1);
			//cout << s2 << endl;
			se.insert(s2);
		}
		printf("%d\n", se.size());
	}
    return 0;
}

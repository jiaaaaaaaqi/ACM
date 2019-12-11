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
const int maxn = 505;
const int maxm = 10000007;
const int mod = 1000000020;
using namespace std;

int n, m, tol, T;
char s[maxn];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s+1);
		int len = strlen(s+1);
		for(int i=1; i<=len; i++) {
			if(s[i] == '?') {
				s[i] = '1';
				if(i-2>=1 && s[i-1] == '0' && !isdigit(s[i-2])) {
					s[i] = '+';
				}
			}
		}
		bool flag = true;
		for(int i=1; i<=len; i++) {
			if(!isdigit(s[i]) && !isdigit(s[i-1])) {
				flag = false;
				break;
			}
			if(!isdigit(s[i]) && s[i+1] == '0') {
				flag = false;
				break;
			}
		}
		if(!isdigit(s[1]) || !isdigit(s[len]))	flag = false;
		if(s[1] == '0')	flag = false;
		flag ? printf("%s\n", s+1) : printf("IMPOSSIBLE\n");
	}
    return 0;
}

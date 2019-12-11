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

bool ok(char ch) {
    if(ch >= '0' && ch <= '9')
        return 1;
    if(ch == '+' || ch == '*')
        return 0;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s+1);
        int len = strlen(s+1);
        for(int i=1; i<=len; i++) {
            if(s[i] == '?') {
                s[i] = '1';
                if(i-2>=1 && s[i-1] == '0' && !ok(s[i-2])) {
                    s[i] = '+';
                }
            }
        }
        bool flag = true;
        for(int i=2; i<=len; i++) {
            if(!ok(s[i]) && !ok(s[i-1])) {
                flag = false;
                break;
            }
        }
        for(int i=1; i<=len-2; i++) {
            if(!ok(s[i]) && s[i+1] == '0' && ok(s[i+2])) {
                flag = false;
                break;
            }
        }
        if(len > 1 && s[1] == '0')		flag = false; 
        if(!ok(s[1]) || !ok(s[len]))	flag = false;
        flag ? printf("%s\n", s+1) : printf("IMPOSSIBLE\n");
    }
    return 0;
}

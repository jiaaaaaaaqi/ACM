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

char s[20][20], c[2];

bool check() {
    for(int i=1; i<=3; i++) {
        if(s[i][1]==c[0] && s[i][2]==c[0] && s[i][3]==c[0])
            return true;
    }
    for(int j=1; j<=3; j++) {
        if(s[1][j]==c[0] && s[2][j]==c[0] && s[3][j]==c[0])
            return true;
    }
    if(s[1][1]==c[0] && s[2][2]==c[0] && s[3][3]==c[0])
        return true;
    if(s[1][3]==c[0] && s[2][2]==c[0] && s[3][1]==c[0])
        return true;
	return false;
}

bool ok() {
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            if(s[i][j] == '.') {
                s[i][j] = c[0];
                if(check()) {
					s[i][j] = '.';
					return true;
                }
                s[i][j] = '.';
            }
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    n = 3;
    while(T--) {
        mes(s, 0);
        char cc[5];
        for(int i=1; i<=3; i++) {
            for(int j=1; j<=3; j++) {
                scanf("%s", cc);
                s[i][j] = cc[0];
            }
        }
        scanf("%s", cc);
        c[0] = cc[0];
        if(c[0] == 'o')	c[1] = 'x';
        else	c[1] = 'o';
        if(check()) {
			printf("Kim win!\n");
			continue;
        }
        bool ans = false;
        for(int i=1; i<=3; i++) {
            for(int j=1; j<=3; j++) {
                if(s[i][j] != '.')	continue;
                s[i][j] = c[0];
                if(check())	ans = true;
                if(ans)	break;
                bool flag = false;
                for(int ii=1; ii<=3; ii++) {
                    for(int jj=1; jj<=3; jj++) {
                        if(s[ii][jj] != '.')	continue;
                        s[ii][jj] = c[1];
                        if(!ok())	flag = true;
                        s[ii][jj] = '.';
                        if(flag)	break;
                    }
                    if(flag)	break;
                }
                s[i][j] = '.';
                if(flag == false)	ans = true;
                if(ans)	break;
            }
            if(ans)	break;
        }
        if(ans)	printf("Kim win!\n");
        else	printf("Cannot win!\n");
    }
    return 0;
}
/*
2
o x .
. o .
. . x
x
*/

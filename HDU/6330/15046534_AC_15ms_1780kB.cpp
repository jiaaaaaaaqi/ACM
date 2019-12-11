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
const int maxn = 1005;
const int maxm = 1000005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
char maps[200][200];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(maps, 0, sizeof maps);
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        n = 2*c + 2*b + 1;
        m = 2*a + 2*b + 1;
        int tmp = 2*b;
        int tmp2 = tmp;
        for(int i=1; i<=tmp; i++) {
            for(int j=0; j<=tmp2; j++) {
                maps[i][j] = '.';
                maps[n-i+1][m-j+1] = '.';
            }
            tmp2--;
        }
        int flag;
        flag = 1;
        for(int i=tmp+1; i<=m; i++) {
            if(flag) {
                maps[1][i] = '+';
                maps[n][m-i+1] = '+';
            } else {
                maps[1][i] = '-';
                maps[n][m-i+1] = '-';
            }
            flag = !flag;
        }
        flag = 1;
        for(int i=tmp+1; i<=n; i++) {
            if(flag) {
                maps[i][1] = '+';
                maps[n-i+1][m] = '+';
            } else {
                maps[i][1] = '|';
                maps[n-i+1][m] = '|';
            }
            flag = !flag;
        }
        int x = 2*a+1;
        int y = 2*b-1;
        int y1 = 1;
        tmp2 = tmp-1;

        int flag2 = 0;
        for(int k=2; k<=tmp; k++) {
            if(flag2) {
                flag = 1;
                for(int i=tmp2+1; i<m-y1+1; i++) {
                    if(flag)    maps[k][i] = '+';
                    else        maps[k][i] = '-';
                    flag = !flag;
                }
                flag = 1;
                for(int i=m-y1+1; i<=m; i++) {
					if(maps[k][i])	continue;
					if(flag)	maps[k][i] = '.';
					else		maps[k][i] = '+';
					flag = !flag;
                }
            } else {
                flag = 1;
                for(int i=tmp2+1; i<m-y1+1; i++) {
                    if(flag)    maps[k][i] = '/';
                    else        maps[k][i] = '.';
                    flag = !flag;
                }
                flag = 1;
                for(int i=m-y1+1; i<=m; i++) {
					if(maps[k][i])	continue;
					if(flag)	maps[k][i] = '|';
					else		maps[k][i] = '/';
					flag = !flag;
                }
            }
            y1++;
            flag2 = !flag2;
            tmp2--;
        }

        flag = 1;
        x = 2*a+1;
        y = 2*b-1;
        for(int i=tmp+1; i<=n; i++) {
            if(flag) {
                int flag1 = 0;
                for(int j=2; j<=x; j++) {
                    if(flag1)    maps[i][j] = '+';
                    else        maps[i][j] = '-';
                    flag1 = !flag1;
                }
                flag1 = 1;
                for(int j=x+1; j<m; j++) {
                    if(maps[i][j])    continue;
                    if(flag1)    maps[i][j] = '.';
                    else        maps[i][j] = '+';
                    flag1 = !flag1;
                }
            } else {
                int flag1 = 0;
                for(int j=2; j<=x; j++) {
                    if(flag1)    maps[i][j] = '|';
                    else        maps[i][j] = '.';
                    flag1 = !flag1;
                }
                for(int j=x+1; j<m; j++) {
                    if(maps[i][j])    continue;
                    if(flag1)    maps[i][j] = '|';
                    else        maps[i][j] = '/';
                    flag1 = !flag1;
                }
                flag1 = 1;
                for(int i=x+1; i<m; i++) {

                }
            }
            flag = !flag;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++)    {
                printf("%c", maps[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

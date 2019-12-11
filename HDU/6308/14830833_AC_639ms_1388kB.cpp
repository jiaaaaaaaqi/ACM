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
const int maxm = 30005;
const int mod = 1000000007;
using namespace std;

int n, m, tol, T;

int main() {
    scanf("%d", &T);
    while(T--) {
        int beh, bem;
        char str[15];
        scanf("%d%d%s",&beh,&bem,str);
        double op;
        sscanf(str,"%*[A-Z]%lf",&op);
        int x, y, flag;
        flag = op >= 0 ? 1 : -1;
        op += (flag) * 0.0000005;
        op = op*flag;
        x = (int)op;
        op = (op-x)*10.0;
        y = (int)op;
        int enh = flag * x - 8;
        int enm = y * 60 / 10;
        int ansh, ansm;
        ansh = beh + enh;        
        ansm = bem + flag * enm;
        int c = 0;
        if(ansm < 0) {
            ansm += 60;
            c--;
        } else if(ansm >= 60) {
            ansm -= 60;
            c++;
        }
        ansh += c;
        if(ansh < 0) {
            ansh += 24;
        } else if(ansh >= 24) {
            ansh -= 24;
        }
        printf("%02d:%02d\n", ansh, ansm);
    }
    return 0;
}
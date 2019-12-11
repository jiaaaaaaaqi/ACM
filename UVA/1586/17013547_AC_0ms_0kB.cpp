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
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        char str[200] = {0};
        double quality = 0;
        gets(str);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if ((str[i + 1] > '9' || str[i + 1] < '0') || i + 1 == len)
            {
                if (str[i] == 'C')
                    quality += 12.01;
                else if (str[i] == 'H')
                    quality += 1.008;
                else if (str[i] == 'O')
                    quality += 16.00;
                else if (str[i] == 'N')
                    quality += 14.01;
                else {
                    int x = 1;
                    x /= 0;
                }
            }
            else
            {
                int multiple;
                if (str[i + 2] <= '9' && str[i + 2] >= '0' && i + 2 != len)
                    multiple = (str[i + 1] - '0') * 10 + (str[i + 2] - '0');
                else
                    multiple = str[i + 1] - '0';
                if (str[i] == 'C')
                    quality += 12.01 * multiple;
                else if (str[i] == 'H')
                    quality += 1.008 * multiple;
                else if (str[i] == 'O')
                    quality += 16.00 * multiple;
                else
                    quality += 14.01 * multiple;
                if (multiple > 9)
                    i += 2;
                else
                    i++;
            }
        }
        printf("%.3f\n", quality);
    }
    return 0;
}

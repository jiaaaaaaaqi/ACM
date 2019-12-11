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

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 10 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node{
    int x, y;
} node[maxn];
vector<int> bian[2];
/*
bool istriangles(int i, int j, int k, int id) {
    vector<int> vv;
    vv.clear();
    vv.push_back((node[i].x-node[j].x)*(node[i].x-node[j].x) + (node[i].y-node[j].y)*(node[i].y-node[j].y));
    vv.push_back((node[j].x-node[k].x)*(node[j].x-node[k].x) + (node[j].y-node[k].y)*(node[j].y-node[k].y));
    vv.push_back((node[i].x-node[k].x)*(node[i].x-node[k].x) + (node[i].y-node[k].y)*(node[i].y-node[k].y));
    sort(vv.begin(), vv.end());
    if(sqrt(1.0*vv[0]) + sqrt(1.0*vv[1]) > sqrt(1.0*vv[2])) {
        bian[id].clear();
        bian[id].push_back(vv[0]);
        bian[id].push_back(vv[1]);
        bian[id].push_back(vv[2]);
//        printf("%lld %lld %lld\n", vv[0], vv[1], vv[2]);
        return 1;
    }
    else    return 0;
}*/
bool istriangles(int i, int j, int k, int id) {
	bian[id].clear();
    int det = (node[j].y-node[k].y)*(node[i].x-node[k].x) - (node[j].x-node[k].x)*(node[i].y-node[k].y);

    if (det > 0)
    {
        bian[id].push_back((node[i].x-node[j].x)*(node[i].x-node[j].x) + (node[i].y-node[j].y)*(node[i].y-node[j].y));
        bian[id].push_back((node[j].x-node[k].x)*(node[j].x-node[k].x) + (node[j].y-node[k].y)*(node[j].y-node[k].y));
        bian[id].push_back((node[i].x-node[k].x)*(node[i].x-node[k].x) + (node[i].y-node[k].y)*(node[i].y-node[k].y));
    }
    else if (det < 0)
    {
        bian[id].push_back((node[i].x-node[j].x)*(node[i].x-node[j].x) + (node[i].y-node[j].y)*(node[i].y-node[j].y));
        bian[id].push_back((node[i].x-node[k].x)*(node[i].x-node[k].x) + (node[i].y-node[k].y)*(node[i].y-node[k].y));
        bian[id].push_back((node[j].x-node[k].x)*(node[j].x-node[k].x) + (node[j].y-node[k].y)*(node[j].y-node[k].y));
    }
    return det;
}

bool ok() {
    if(bian[0][0] != bian[1][0])    return false;
    if(bian[0][1] != bian[1][1])    return false;
    if(bian[0][2] != bian[1][2])    return false;
    return true;
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i=1; i<=n; i++) {
            scanf("%d%d", &node[i].x, &node[i].y);
        }
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            for(int j=i+1; j<=n; j++) {
                for(int k=j+1; k<=n; k++) {
                    if(!istriangles(i, j, k, 0))  continue;
                    for(int x=1; x<=n; x++) {
                        if(x==i || x==j || x==k)    continue;
                        for(int y=x+1; y<=n; y++) {
                            if(y==i || y==j || y==k)    continue;
                            for(int z=y+1; z<=n; z++) {
                                if(z==i || z==j || z==k)    continue;
                                if(!istriangles(x, y, z, 1))  continue;
                                for (int ii = 0; ii <= 2; ii++)
                                {
                                    bool flag = true;
                                    for (int jj = 0; jj <= 2; jj++)
                                    {
                                        if (bian[0][jj] != bian[1][(ii+jj)%3])
                                        {
                                            flag = false;
                                            break;
                                        }
                                    }
                                    if (flag)
                                    {
                                        cnt++;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", cas++, cnt);
    }
	return 0;
}
/*
1
6
0 0
2 0
2 1
8 8
10 8
10 7
*/

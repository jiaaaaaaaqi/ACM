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
const int maxn = 1e7;
const int maxm = 1e11;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
int s[10][10];
int c[10][10];
map<ll, bool> vis;

bool check() {
	vis.clear();
	int cnt = 0;
    for(int i=1; i<=6; i++) {
		if(!vis[s[i][1]])	cnt++;
		vis[s[i][1]] = true;
        for(int j=2; j<=4; j++) {
            if(s[i][j] != s[i][j-1])	return false;
        }
    }
    if(cnt != 6)	return false;    
    return true;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        char ch;
        memset(c, 0, sizeof c);
        for(int i=1; i<=2; i++) {
            for(int j=1; j<=4; j++) {
                scanf("%d", &c[i][j]);
            }
        }
        scanf("%d", &c[3][3]);
        scanf("%d", &c[3][4]);
        scanf("%d", &c[3][1]);
        scanf("%d", &c[3][2]);

        scanf("%d", &c[4][3]);
        scanf("%d", &c[4][4]);
        scanf("%d", &c[4][1]);
        scanf("%d", &c[4][2]);

        scanf("%d", &c[5][3]);
        scanf("%d", &c[5][1]);
        scanf("%d", &c[5][4]);
        scanf("%d", &c[5][2]);

        scanf("%d", &c[6][2]);
        scanf("%d", &c[6][4]);
        scanf("%d", &c[6][1]);
        scanf("%d", &c[6][3]);

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[1][1];
        s[1][1] = s[4][3];
        s[4][3] = s[3][3];
        s[3][3] = s[2][1];
        s[2][1] = ch;
        ch = s[1][3];
        s[1][3] = s[4][1];
        s[4][1] = s[3][1];
        s[3][1] = s[2][3];
        s[2][3] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[1][1];
        s[1][1] = s[2][1];
        s[2][1] = s[3][3];
        s[3][3] = s[4][3];
        s[4][3] = ch;
        ch = s[1][3];
        s[1][3] = s[2][3];
        s[2][3] = s[3][1];
        s[3][1] = s[4][1];
        s[4][1] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[1][3];
        s[1][3] = s[6][1];
        s[6][1] = s[3][4];
        s[3][4] = s[5][4];
        s[5][4] = ch;
        ch = s[1][4];
        s[1][4] = s[6][3];
        s[6][3] = s[3][3];
        s[3][3] = s[5][2];
        s[5][2] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[1][3];
        s[1][3] = s[5][4];
        s[5][4] = s[3][4];
        s[3][4] = s[6][1];
        s[6][1] = ch;
        ch = s[1][4];
        s[1][4] = s[5][2];
        s[5][2] = s[3][3];
        s[3][3] = s[6][3];
        s[6][3] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[2][1];
        s[2][1] = s[6][1];
        s[6][1] = s[4][2];
        s[4][2] = s[5][1];
        s[5][1] = ch;
        ch = s[2][2];
        s[2][2] = s[6][2];
        s[6][2] = s[4][1];
        s[4][1] = s[5][2];
        s[5][2] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }

        for(int i=1; i<=6; i++)	for(int j=1; j<=4; j++)	s[i][j] = c[i][j];
        ch = s[2][1];
        s[2][1] = s[5][1];
        s[5][1] = s[4][2];
        s[4][2] = s[6][1];
        s[6][1] = ch;
        ch = s[2][2];
        s[2][2] = s[5][2];
        s[5][2] = s[4][1];
        s[4][1] = s[6][2];
        s[6][2] = ch;
        if(check()) {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}
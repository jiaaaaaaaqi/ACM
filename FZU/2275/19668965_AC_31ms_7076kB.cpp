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
const int    maxn = 1e6 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

char s1[maxn], s2[maxn], s3[maxn];
int nex[maxn];

void nextable(char *s, int len) {
    mes(nex, 0);
    nex[0] = -1;
    int i=1, j = 0;
    while(i < len) {
        if(j==-1 || s[i]==s[j])	nex[++i] = ++j;
        else j = nex[j];
    }
}

bool kmp(char *s1, char *s2, int len1, int len2) {
    int i=0, j=0;
    while(i<len1) {
        if(j==-1 || s1[i]==s2[j])	i++, j++;
        else	j = nex[j];
        if(j==len2)	return true;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        mes(s1, 0);
        mes(s2, 0);
        mes(s3, 0);
        scanf("%s%s", s1, s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        while(len1 && s2[len1-1] == '0') {
            s1[len1-1] = '\0';
            len1--;
        }

        while(len2 && s2[len2-1] == '0') {
            s2[len2-1] = '\0';
            len2--;
        }
        nextable(s2, len2);
        if(kmp(s1, s2, len1, len2)) {
            printf("Alice\n");
            continue;
        }
        for(int i=0; i<len2; i++) {
            s3[i] =s2[len2-i-1];
        }
        nextable(s3, len2);
        if(kmp(s1, s3, len1, len2)) {
            printf("Alice\n");
            continue;
        }
        printf("Bob\n");
    }
    return 0;
}

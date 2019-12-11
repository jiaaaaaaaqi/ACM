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
const int maxn = 1e6+10;
const int maxm = 1e9;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
char s[maxn];
int nex[maxn];

void init() {
	memset(s, 0, sizeof s);
}

void make_next_table(int len) {
    memset(nex, 0, sizeof nex);
    nex[0] = -1;
    int i = 1;
    int j = 0;
    while(i < len) {
        if(j == -1 || s[i] == s[j])		nex[++i] = ++j;
        else	j = nex[j];
    }
}

bool kmp(char *s1, char *s2, int len1, int len2) {
    int i = 0;
    int j = 0;
    while(i < len1) {
        if(j == -1 || s1[i] == s2[j])	i++, j++;
        else	j = nex[j];
        if(j == len2)	return true;
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
		init();
        scanf("%s", s);
        int ans = 0;
        int len = strlen(s);
        if(len < 3) {
            printf("0\n");
            continue;
        }
        make_next_table(len);
//        for(int i=0; i<=len; i++)	printf("%d%c", nex[i], i==len ? '\n' : ' ');
        for(int i=nex[len]; ~i && !ans; i=nex[i]) {
            if(i >= len-i)	continue;
//            for(int j=i, t=0; t<len-2*i; j++, t++)	printf("%c", s[j]);
//            printf("\n");
//            for(int j=0; j<i; j++)	printf("%c", s[j]);
//            printf("\n");
            if(kmp(s+i, s, len-2*i, i)) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

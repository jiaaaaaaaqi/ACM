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
char t[maxn];
char s[maxn];
char str[maxn];
int nex[maxn];
/*
void make_next_table() {
	memset(nex, 0, sizeof nex);
	nex[0] = -1;
	int i = 1;
	int j = 0;
	int len = strlen(s);
	while(i < len) {
		if(j == -1 || s[i] == s[j])		nex[++i] = ++j;
		else	j = nex[j];
	}
}

bool kmp() {
	make_next_table();
	int i = 0;
	int j = 0;
	int len1 = strlen(str);
	int len2 = strlen(s);
	while(i < len1) {
		if(j == -1 || str[i] == s[j])	i++, j++;
		else	j = nex[j];
		if(j == len2)	return true;
	}
	return false;
}
*/

void make_next_table() {
    memset(nex, 0, sizeof nex);
    nex[0] = -1;
    int i = 1;
    int j = 0;
    int len = strlen(s);
    while(i < len) {
        if(j == -1 || s[i] == s[j]) {
            nex[++i] = ++j;
        } else {
            j = nex[j];
        }
    }
}

bool kmp() {
    int len1 = strlen(str);
    int len2 = strlen(s);
    make_next_table();
    int i = 0;
    int j = 0;
    while(i < len1) {
        if(j == -1 || str[i] == s[j]) {
            i++, j++;
        } else {
            j = nex[j];
        }
        if(j == len2) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%s", t);
        int len = strlen(t);
        int ans = 0;
        for(int l=1; l<=len/3; l++) {
            memset(s, 0, sizeof s);
            for(int i=0; i<l; i++)	s[i] = t[i];
            bool flag = true;
            if(len-l <= l-1)	flag = false;
            if(!flag)	break;
            for(int i=len-l, j=0; i<len; i++, j++) {				
                if(t[i] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if(!flag)	break;
            for(int i=l+1, j=0; i<len-1-l; i++, j++)	str[j] = t[i];
            if(kmp()) {
                ans = l+1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

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
const int maxn = 250000;
const int maxm = 1e9;
const int mod = 998244353;
using namespace std;

int n, m;
int T, tol;
char s[10] = "doge";
char t[1005];
int nex[10];
int ans;

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
    //for(int i=0; i<len; i++)	printf("%d%c", nex[i], i==len-1 ? '\n' : ' ');
}

void kmp() {
	int len1 = strlen(t);
	int len2 = strlen(s);
	int i = 0;
	int j = 0;
	while(i < len1) {
		if(j == -1 || t[i] == s[j]) {
			i++, j++;
		} else {
			j = nex[j];
		}
		if(j == len2) {
			ans++;
			j = nex[j];
		}
	}
}

int main() {
    make_next_table();
	ans = 0;
    while(gets(t) != NULL) {
		int len = strlen(t);
		for(int i=0; i<len; i++)	t[i] = tolower(t[i]);
		kmp();
    }
    printf("%d\n", ans);
    return 0;
}

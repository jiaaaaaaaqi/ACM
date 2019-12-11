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
const int maxn = 1100;
const int maxm = 2010;
const int mod = 998244353;
using namespace std;

ll n, m;
int T, tol;
char s[maxn];
int nex[maxn];
set<string> se;

void make_next_table(char *s, int len) {
    memset(nex, 0, sizeof nex);
    nex[0] = -1;
    int i = 1;
    int j = 0;
    while(i < len) {
        if(j == -1 || s[i] == s[j])	nex[++i] = ++j;
        else	j = nex[j];
    }
}

bool kmp(char *s1, int len1, char *s2, int len2, int p) {
    if(len1 == 0)	return false;
//	for(int i=0; i<len1; i++)	printf("%c", s1[i]);	printf("  ");
//	for(int i=0; i<len2; i++)	printf("%c", s2[i]);	printf("\n");
//	make_next_table(s2, len2);
    int i = 0;
    int j = 0;
    while(i < len1) {
        if(j == -1 || s1[i] == s2[j])	i++, j++;
        else {
            j = nex[j];
        }
        if(j == len2)	return true;
    }
    return false;
}

int main() {
    while(1) {
        se.clear();
        scanf("%s", s);
        if(s[0] == '#')		break;
        int len = strlen(s);
        make_next_table(s, len);
        int mx = len/2;
        int ans = 0;
        for(int l=1; l<=mx; l++) {
            for(int i=0; i<len; i++) {
                if(i + l - 1 >= len)		break;
                bool flag = false;
                string s3;
                for(int j=i, t=0; t<l; j++, t++)	s3 += s[j];
                if(se.count(s3))	break;
                if(kmp(s, i, s+i, l, i))	flag = true;
                if(flag) {
                    se.insert(s3);
                    ans++;
                    continue;
                }
                if(kmp(s+i+l, len-i-l, s+i, l, i))	flag = true;
                if(flag) {
                    se.insert(s3);
                    ans++;
                    continue;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

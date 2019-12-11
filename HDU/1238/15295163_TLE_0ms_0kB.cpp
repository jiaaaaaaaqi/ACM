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
const int maxn = 100005;
const int maxm = 1e11;
const int mod = 10007;
using namespace std;

int n, m;
int T, tol;
char s[105][105];
char t1[105];
char t2[105];
int nex[maxn];

void init() {
	memset(s, 0, sizeof s);
}

void make_next_table(char t[], int len) {
	memset(nex, 0, sizeof nex);
	nex[0] = -1;
	int i = 1;
	int j = 0;
	while(i < len) {
		if(j == -1 || t[i] == t[j]) {
			nex[++i] = ++j;
		} else {
			j = nex[j];
		}
	}
}

bool kmp(char s1[], char s2[]) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	make_next_table(s2, len2);
	int i = 0;
	int j = 0;
	while(i < len1) {
		if(j == -1 || s1[i] == s2[j]) {
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
		init();
		scanf("%d", &n);
		int mx = 1;		
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]);
			mx = strlen(s[mx]) <= strlen(s[i]) ? mx : i;
		}
		swap(s[1], s[mx]);
		int len = strlen(s[1]);
		//for(int i=1; i<=n; i++)	printf("%s\n", s[i]);
		mx = 0;
		for(int l=1; l<=len; l++) {
			for(int i=0; i<len; i++) {
				if(i+l > len)	continue;
				int cnt = 0;
				memset(t1, 0, sizeof t1);
				memset(t2, 0, sizeof t2);
				for(int j=i; cnt<l; j++) {
					t1[cnt] = s[1][j];
					cnt++;
				}
				for(int j=0; j<l; j++) {
					t2[j] = t1[l - j - 1];
				}
				//printf("%s %s\n", t1, t2);
				bool f = true;
				for(int j=2; j<=n; j++) {
					bool flag = false;
					if(kmp(s[j], t1))	flag = true;
					if(kmp(s[j], t2))	flag = true;
					if(!flag) {
						f = false;
						break;
					}
				}
				if(f)	mx = max(mx, l);
			}
		}
		printf("%d\n", mx);
	}
    return 0;
}

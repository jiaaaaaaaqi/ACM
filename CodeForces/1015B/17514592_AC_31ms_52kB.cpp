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
const int maxn = 55;
const int maxm = 50005;
const int mod = 10007;
using namespace std;

int n, m, tol, T;
char str1[maxn];
char str2[maxn];
int cnt1[maxn];
int cnt2[maxn];
int step[10005];

int main() {
	tol = 0;
	scanf("%d", &n);
	scanf("%s%s", str1+1, str2+1);
	for(int i=1; i<=n; i++)	cnt1[str1[i]-'a'+1]++;
	for(int i=1; i<=n; i++)	cnt2[str2[i]-'a'+1]++;
	for(int i=1; i<=26; i++)	if(cnt1[i] != cnt2[i]) {printf("-1\n");return 0;}
	for(int i=1; i<=n; i++) {
		if(str1[i] == str2[i])	continue;
		char ch = str2[i];
		int j = i;
		for(; j<=n; j++) {
			if(str1[j] == ch)	break;
		}
		for(int k=j-1; k>=i; k--) {
			step[++tol] = k;
			swap(str1[k], str1[k+1]);
		}
	}
	printf("%d\n", tol);
	for(int i=1; i<=tol; i++)	printf("%d%c", step[i], i==tol ? '\n' : ' ');
    return 0;
}
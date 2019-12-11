#include<map>
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
const int maxm = 205;
const int mod = 1000000007;
using namespace std;

int n, m, tol;
char str1[maxn];
char str2[maxn];

int check(int i, int j) {
    int num = 0;
    if(str1[i] == str2[i]) 	num++;
    if(str1[i] == str2[j])	num++;
    if(str1[j] == str2[i])	num++;
    if(str1[j] == str2[j])	num++;
    return num;
}

int main() {
    scanf("%d", &n);
    memset(str1, 0, sizeof str1);
    memset(str2, 0, sizeof str2);
    scanf("%s%s", str1 + 1, str2 + 1);
    int ans = 0;
    int x = (n + 1) / 2;
    if((n & 1) == 1 && str1[x] != str2[x])	ans = 1;
    m = n / 2;
    for(int i=1; i<=m; i++) {
        int j = n - i + 1;
        if(str1[i] == str2[i] && str1[j] == str2[j])	continue;
        int cnt = check(i, j);
        if(cnt == 0) {
            if(str1[i] == str1[j] && str2[i] == str2[j])	continue;
			ans += 2;
            if(str2[i] == str2[j])	ans--;
            continue;
        } else if(cnt == 1) {
			ans++;
			continue;
        } else if(cnt = 2) {
			if(str1[i] == str2[j] && str1[j] == str2[i])
				ans = ans;
			else
				ans++;
			continue;
        } else if(cnt == 3) {
			continue;
        }
    }
    printf("%d\n", ans);
    return 0;
}
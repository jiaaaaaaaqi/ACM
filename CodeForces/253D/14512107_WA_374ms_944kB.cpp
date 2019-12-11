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
const int maxn = 405;
const int maxm = 305;
using namespace std;

int n, m, tol;
char str[maxn][maxn];
int num[maxn][maxn];
int cnt[30];

void init() {
	memset(str, 0, sizeof str);
	memset(num, 0, sizeof num);
}

int main() {
	int k;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(~scanf("%d%d%d", &n, &m, &k)) {
		init();
		for(int i=1; i<=n; i++) {
			scanf("%s", str[i] + 1);
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				int x = str[i][j] == 'a';
				num[i][j] = num[i][j-1] + x;
			}
		}
		int ans = 0;
		for(int left=1; left<m; left++) {
			for(int right=left+1; right<=m; right++) {
				int sum = 0;
				memset(cnt, 0, sizeof cnt);
				int bottom = 1;
				int top = 1;
				for(bottom=top; bottom<=n; bottom++) {
                    sum += num[bottom][right] - num[bottom][left - 1];
                    if(str[bottom][left] == str[bottom][right]) {
						cnt[str[bottom][left] - 'a']++;
                    }
                    while(sum > k && top <= bottom) {
						sum -= num[top][right] - num[top][left - 1];
						if(str[top][left] == str[top][right]) {
							cnt[str[top][left] - 'a']--;
						}
						top++;
                    }
                    if(top < bottom && str[bottom][left] == str[bottom][right]) {
						ans += cnt[str[bottom][left] - 'a'] - 1;
                    }
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

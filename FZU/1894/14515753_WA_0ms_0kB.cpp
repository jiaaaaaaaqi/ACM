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
const int maxn = 1000005;
const int maxm = 305;
using namespace std;

int n, m, tol;
ll que[maxn];
ll num[maxn];

void init() {
	tol = 0;
	memset(que, 0, sizeof que);
	memset(num, 0, sizeof num);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		ll x;
		int head = 0;
		int tail = 0;
		int fir = 0;
		int k = 0;
		char str[10], s[10];
		while(1) {
			scanf("%s", str);
			if(strcmp(str, "START") == 0)	continue;
			if(strcmp(str, "END") == 0)		break;
			if(str[0] == 'C') {
				scanf("%s%d", s, &num[k]);
				while(head < tail && num[k] > num[que[tail]])
					tail--;
				que[tail++] = k++;
			} else if(str[0] == 'G') {
				fir++;
				while(que[head] < fir)
					head++;
			} else if(str[0] == 'Q') {
				if(head < tail)	printf("%lld\n", num[que[head]]);
				else	printf("-1\n");
			}
		}
	}
	return 0;
}

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
int que[maxn];

void init() {
	tol = 0;
	memset(que, 0, sizeof que);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int x;
		int head = 0;
		int tail = 0;
		char str[10], s[10];
		while(1) {
			scanf("%s", str);
			if(strcmp(str, "START") == 0)	continue;
			if(strcmp(str, "END") == 0)		break;
			if(str[0] == 'C') {
				scanf("%s%d", s, &x);
				while(head < tail && que[tail - 1] < x) tail--;
				que[tail++] = x;
			} else if(str[0] == 'G') {
				head++;
			} else if(str[0] == 'Q') {
				if(head == tail)	printf("-1\n");
				else	printf("%d\n", que[head]);
			}
		}
	}
	return 0;
}

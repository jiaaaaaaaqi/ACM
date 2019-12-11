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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 105;
using namespace std;

int n, m, tol;
struct Node {
    int num;
    int id;
};
Node node[maxn];
int ans[maxn];
int num[maxn];
int head;

void init() {
    memset(ans, 0, sizeof ans);
    memset(num, 0, sizeof num);
}

int find(int x) {
    int left = 0;
    int right = head - 1;
    while(left <= right) {
		int mid = (left + right) >> 1;
		if(node[mid].num >= x) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
    }
    return node[left].id;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i=1; i<=n; i++) {
            scanf("%d", &num[i]);
        }
        for(int i=n; i>=1; i--) {
            if(head && node[head - 1].num < num[i]) {
                ans[i] = find(num[i]) - i - 1;
            } else {
                ans[i] = -1;
                node[head].id = i;
                node[head].num = num[i];
                head++;
            }
        }
        for(int i=1; i<=n; i++)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}

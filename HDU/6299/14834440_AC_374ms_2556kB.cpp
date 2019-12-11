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
#define first fi
#define second se
#define lowbit(x) (x & (-x))

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
const int maxm = 12;
using namespace std;

int n, m, tol, T;
struct Node {
    int l, r;
    Node () {
        l = r = 0;
    }
    bool operator < (Node a) const {
		if(r == 0)		return 1;
		if(a.r == 0)	return 0;
		if(l >= r && a.l < a.r)	return 1;
		if(l < r && a.l >= a.r)	return 0;
		if(l >= r && a.l >= a.r)	return r < a.r;
		else	return l > a.l;
    }
};
Node node[maxn];
char str[maxn];

void init() {
    memset(node, 0, sizeof node);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        init();
        scanf("%d", &n);
        int ans = 0;
        for(int i=1; i<=n; i++) {
            stack<char> s;
            scanf("%s", str+1);
            int len = strlen(str+1);
            for(int i=1; i<=len; i++) {
                if(str[i] == '(')	s.push(str[i]);
                if(str[i] == ')') {
                    if(!s.empty() && s.top() == '(') {
                        ans+=2;
                        s.pop();
                    } else {
                        s.push(str[i]);
                    }
                }
            }
            while(!s.empty()) {
                char ch = s.top();
                if(ch == '(')	node[i].l++;
                else	node[i].r++;
                s.pop();
            }
        }
		sort(node+1, node+1+n);
		int L = 0;
		for(int i=1; i<=n; i++) {
			if(L >= node[i].r) {
				ans += 2*node[i].r;
				L -= node[i].r;
			} else {
				ans += 2*L;
				L = 0;
			}
			L += node[i].l;
		}
		printf("%d\n", ans);
    }
    return 0;
}

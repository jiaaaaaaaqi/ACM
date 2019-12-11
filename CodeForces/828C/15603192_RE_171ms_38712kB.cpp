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
#define INOPEM freopen("in.txt", "r", stdin)
#define OUTOPEN freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e6+10;
const int maxm = 1e6+10;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
struct Node {
    int len;
    int pos;
    string t;
    bool operator < (Node a) const {
        return len > a.len;
    }
};
Node node[maxm];
struct Edge {
    int id;
    Edge () {
        id = 0;
    }
};
Edge s[maxn];
char str[maxn];

int main() {
    scanf("%d", &n);
    string x;
    int pos;
    tol = 1;
    int mx = 0;
    for(int i=1; i<=n; i++) {
        cin >> x;
        int len = x.size();
        scanf("%d", &m);
        for(int i=1; i<=m; i++) {
            scanf("%d", &pos);
            node[tol].len = len;
            node[tol].pos = pos;
            node[tol++].t = x;
            mx = max(mx, pos+len);
        }
    }
    sort(node+1, node+tol);
//    for(int i=0; i<tol; i++) {
//		printf("%d %d %d ", i, node[i].len, node[i].pos);
//		cout << node[i].t << endl;
//    }
    for(int i=0; i<tol; i++) {
        int pos = node[i].pos;
        int id = s[pos].id;
        if(!id)	s[pos].id = i;
        int len1 = node[i].len;
        int len2 = node[id].len;
        if(len1 > len2) {
            id = i;
        }
    }
//    for(int i=1; i<=mx; i++)	printf("%d %d %c", i, s[i].id, i==mx ? '\n' : ' ');
    for(int i=1; i<mx; i++) {
		if(s[i].id == 0) {
			if(str[i])	continue;
			else	str[i] = 'a';
			continue;
		}
		int len = node[s[i].id].len;
//		cout << node[s[i].id].t << endl;
		for(int j=0; j<len; j++) {
			str[i+j] = node[s[i].id].t[j];
		}
    }
    printf("%s\n", str+1);
    return 0;
}

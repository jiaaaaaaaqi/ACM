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
const int maxn = 10000005;
const int maxm = 1 << 29;
using namespace std;

int n, m, tol;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Node {
    int time;
    int val;
};
Node node[2505];
deque<pair<int, ll> > q;

void init() {
    q.clear();
    memset(node, 0, sizeof node);
}

bool runnian(int year) {
    return year%4 == 0 && year%100 || year%400 == 0;
}

int calcmonth(char *str) {
    if(strcmp(str, "Jan") == 0)	return 1;
    if(strcmp(str, "Feb") == 0)	return 2;
    if(strcmp(str, "Mar") == 0)	return 3;
    if(strcmp(str, "Apr") == 0)	return 4;
    if(strcmp(str, "May") == 0)	return 5;
    if(strcmp(str, "Jun") == 0)	return 6;
    if(strcmp(str, "Jul") == 0)	return 7;
    if(strcmp(str, "Aug") == 0)	return 8;
    if(strcmp(str, "Sep") == 0)	return 9;
    if(strcmp(str, "Oct") == 0)	return 10;
    if(strcmp(str, "Nov") == 0)	return 11;
    if(strcmp(str, "Dec") == 0)	return 12;
}

int calchour(char *str, int d, int y, int h) {
    int ans = 0;
    for(int i=2000; i<y; i++) {
        if(runnian(i))	ans += 366;
        else	ans += 365;
    }
    int month = calcmonth(str);
    for(int i=1; i<month; i++) {
        if(i == 2) {
            if(runnian(y))	ans += 29;
            else	ans += 28;
        } else {
			ans += day[i];
        }
    }
    ans += (d - 1);
    return ans * 24 + h + 1;
}

int main() {
    while(scanf("%d%d", &n, &m), n||m) {
        init();
        for(int i=1; i<=n; i++) {
            char str[10];
            int d, y, h, val;
            memset(str, 0, sizeof str);
            scanf("%s%d%d%d%d", str, &d, &y, &h, &val);
            node[i].time = calchour(str, d, y, h);
            node[i].val = val;
        }
        int low, cost;
        scanf("%d%d", &low, &cost);
        ll x;
        __int64 ans = 0;
        int cnt = 1;
        for(int i=1; i<=m; i++) {
            scanf("%lld", &x);
            while(!q.empty() && (q.back().second + (i - q.back().first) * cost) >= x)
                q.pop_back();
            q.push_back(make_pair(i, x));
            while(cnt <= n && node[cnt].time == i) {
                while(!q.empty() && (q.front().first + low < i))
                    q.pop_front();
                ans += (q.front().second + (i - q.front().first) * cost) * node[cnt].val;
                cnt++;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

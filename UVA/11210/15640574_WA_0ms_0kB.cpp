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
const int maxn = 2e6+5;
const int maxm = 1005000;
const int mod = 1e9+7;
using namespace std;

int n, m;
int T, tol;
char *Mahjong[39] = {
    "0", "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
    "0", "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
    "0", "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W", //29
    "0", "DONG", "NAN", "XI", "BEI",
    "0", "ZHONG", "FA", "BAI"//38
};
int cnt[40];
int id[15];

void init() {
    memset(cnt, 0, sizeof cnt);
}

int find(char *s) {
    for(int i=0; i<40; i++)
        if(strcmp(s, Mahjong[i]) == 0)
            return i;
}

bool dfs(int count) {
	if(count == 14)	return true;
	else	return false;	
	for(int i=1; i<=39; i++) {
		if(cnt[i] >= 3) {
			cnt[i] -= 3;
			if(dfs(count+3))	return true;
			cnt[i] += 3;
		}
	}
	for(int i=1; i<=29; i++) {
		if(cnt[i] >= 1 && cnt[i+1] >= 1 && cnt[i+2] >= 1) {
			cnt[i] -= 1, cnt[i+1] -= 1, cnt[i+2] -= 1;
			if(dfs(count+3))	return true;
			cnt[i] += 1, cnt[i+1] += 1, cnt[i+2] += 1;
		}
	}
	return false;
}

bool judge() {
	for(int i=1; i<=39; i++) {
		if(cnt[i] >= 2) {
			cnt[i] -= 2;
			if(dfs(2))	return true;
			cnt[i] += 2;
		}
	}
	return false;
}

int main() {
    char tmp[10];
    int cas = 1;
    while(scanf("%s", tmp)) {
        if(tmp[0] == '0')	break;
        init();
        id[1] = find(tmp);
        for(int i=2; i<=13; i++) {
            scanf("%s", tmp);
            id[i] = find(tmp);
        }
        printf("Case %d:", cas++);
        bool flag = false;
        for(int i=0; i<=38; i++) {
            if(Mahjong[i][0] == '0')	continue;
            memset(cnt, 0, sizeof cnt);
            for(int j=1; j<=13; j++)	cnt[id[j]]++;
            if(cnt[i] >= 4)	continue;
            cnt[i]++;
            if(judge()) {
                flag = true;
                printf(" %s", Mahjong[i]);
            }
        }
        if(!flag)	printf(" Not ready");
        printf("\n");
    }
    return 0;
}

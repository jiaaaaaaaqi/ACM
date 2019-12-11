#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int pro;
	int time;
};

bool cmp(node a, node b) {
	return a.pro > b.pro;
}
node sha[10005];
bool vis[10005];

void init() {
	memset(vis, 0, sizeof(vis));
	memset(sha, 0, sizeof(sha));
}

int main() {
	int n;
	while(scanf("%d",&n)!=EOF) {
		init();
		int maxtime=0;
		for(int i=0; i<n; i++) {
			scanf("%d%d",&sha[i].pro, &sha[i].time);
			maxtime=max(maxtime, sha[i].time);
		}
		sort(sha, sha+n, cmp);
		int ans=0;
		for(int i=0; i<n; i++) {
			for(int j=sha[i].time; j>0; j--) {
				if(!vis[j]) {
					vis[j]=true;
					ans+=sha[i].pro;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
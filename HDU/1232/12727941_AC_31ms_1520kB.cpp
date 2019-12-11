#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int boss[1000];

int find(int x) {
	return boss[x]==-1 ? x : boss[x]=find(boss[x]);
}

int bind(int u, int v) {
	int x=find(u);
	int y=find(v);
	if(x!=y) {
		boss[x]=y;
		return 1;
	} else
		return 0;
}

int main() {
	int n,m;
	while(scanf("%d",&m), m) {
		scanf("%d",&n);
		memset(boss, -1, sizeof(boss));
		int ans=m-1;
		while(n--) {
			int u,v;
			scanf("%d%d",&u, &v);
			if(bind(u, v))
				ans--;
		}
		printf("%d\n", ans);
	}
	return 0;
}

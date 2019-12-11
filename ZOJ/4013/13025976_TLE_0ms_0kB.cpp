#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

bool vis[1000005];

void init() {
	memset(vis, false, sizeof(vis));
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		init();
		int n;
		scanf("%d",&n);
		for(int i=0; i<n; i++) {
			int num;
			scanf("%d", &num);
			vis[num] = true;
		}
		bool flag=0;
		int num;
		for(int i=0; i<n; i++) {
			scanf("%d", &num);
			if(vis[num]) {
				flag=1;
				break;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
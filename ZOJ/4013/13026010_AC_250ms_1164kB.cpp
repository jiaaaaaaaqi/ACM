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
		int num;
		for(int i=0; i<n; i++) {
			scanf("%d", &num);
			vis[num] = true;
		}
		int flag=0;
		for(int i=0; i<n; i++) {
			scanf("%d", &num);
			if(vis[num]) 
				flag=num;
		}
		printf("%d\n", flag);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num[100005];

void init() {
	memset(num, 0, sizeof(num));
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			scanf("%d",&num[i]);
		int ans=0;
		if(m) {
			sort(num, num+n);
			for(int i=0; i<m; i++) {
				ans += num[i] * num[2*m-i-1];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
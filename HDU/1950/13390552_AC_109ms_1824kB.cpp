#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 40000;

int num[maxn+5];
int sta[maxn+5];

void init() {
	memset(num, 0, sizeof(num));
	memset(sta, 0, sizeof(sta));
}

int LIS(int n) {
	int top = 1;
	sta[1] = num[0];
	for(int i=1; i<n; i++) {
		if(sta[top] < num[i]) {
			sta[++top] = num[i];
		}
		else {
			int pos = lower_bound(sta+1, sta+top+1, num[i]) - sta;
			sta[pos] = num[i];
		}
	}
	return top;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) 
			scanf("%d", &num[i]);
		int ans = LIS(n);
		printf("%d\n" ,ans);
	}
	return 0;
}
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

const int maxn = 10000001;

int num[maxn];

int main() {
	memset(num, 0, sizeof(num));
	double d = 0.0;
	for(int i=1; i<maxn; i++) {
		d += log10(i);
		num[i] = (int)d + 1;
	}
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", num[n]);
	}
	return 0; 
}
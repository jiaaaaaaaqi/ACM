#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int e_gcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1;
		y = 0;
		return a;
	} else {
		int d = e_gcd(b, a%b, x, y);
		int temp = y;
		y = x - a / b * y;
		x = temp;
		return d;
	}
}

int china(int a[], int b[], int n) {
	int sum = 1;
	int ans = 0;
	for(int i=0; i<n; i++)
		sum *= b[i];
	for(int i=0; i<n; i++) {
		int x, y;
		int aa = sum / b[i];
		int d = e_gcd(b[i], aa, x, y);
		ans = (ans + y * a[i] * aa) %sum;
	}
	return (ans%sum+sum)%sum;
}

int main() {
	int T;
	scanf("%d", &T);
	int time[3] = {23, 28, 33};
	int cas = 1;
	int a[3];
	int d;
	while(scanf("%d%d%d%d",&a[0], &a[1], &a[2], &d) != EOF) {
		if(a[0] == -1 && a[1] == -1 && a[2] == -1)
			break;
		a[0] %= 23;
		a[1] %= 28;
		a[2] %= 33;
		int ans = china(a, time, 3);
		ans -= d;
		if(ans <= 0)
			ans += 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",cas++, ans);
	}
	return 0;
}

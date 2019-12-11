#include<stdio.h>
#include<math.h>
#include<string.h>
#include<set>
using namespace std;
#define ull unsigned long long

set<ull> s;
bool vis[100];

ull fast_pow(ull x,ull n) {
	ull ans=1;
	while(n) {
		if(n&1)
			ans*=x;
		x*=x;
		n/=2;
	}
	return ans;
}

void handle() {
	memset(vis, false, sizeof(vis));
	for(int i=3; i<=90; i++) {
		bool flag = false;
		for(int j=2; j*j<=i; j++) {
			if(i % j == 0) {
				flag = true;
				break;
			}
		}
		if(flag)
			vis[i] = true;
	}
}

int main() {
	s.insert(1);
	handle(); 
	ull n = (ull)pow(2.0, 64.0) - 1;
	ull n1 = (1<<16);
	for(ull i=2; i<=n1; i++) {
		ull n2 = (ull)ceil(log(n)/log(i*1.0));
		for(ull j=4; j<n2; j++) {
			if(vis[j]) {
				s.insert(fast_pow(i, j));
			}
		}
	}
	for(set<ull>::iterator it=s.begin(); it!=s.end(); it++)
		printf("%llu\n",*it);
	return 0;
}
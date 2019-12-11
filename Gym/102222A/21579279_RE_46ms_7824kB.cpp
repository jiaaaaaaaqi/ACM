#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1e6+5;
int n, p, q, m;
unsigned int SA, SB, SC;
ll st[mx];
unsigned int rng61() {
 	SA ^= SA << 16;
 	SA ^= SA >> 5;
 	SA ^= SA << 1;
 	unsigned int t = SA; SA = SB;
 	SB = SC;
 	SC ^= t ^ SA;
 	return SC;
}
ll gen(){
	ll ans = 0;
	int top = 0;
 	scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
 	for(int i = 1; i <= n; i++) {
 		if(rng61() % (p + q) < p){
 			top++;
 			st[top] = max(st[top-1],1ll*rng61()%m+1);
 		}
 		else{
 			top = max(top-1,0);
		 }
		 ans ^= 1ll*i*st[top];
 	}
 	return ans;
}

int main(){
	int ca = 1,t;
	scanf("%d",&t);
	while(t--)
		printf("Case #%d: %lld\n",ca++,gen());
	return 0;
}
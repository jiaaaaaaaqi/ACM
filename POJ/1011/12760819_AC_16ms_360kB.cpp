#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n,sum,num,l;
int sti[65];
bool vis[65];

bool cmp(int a, int b) {
	return a>b;
}

void init(){
	memset(sti, 0, sizeof(sti));
}

bool dfs(int s, int le, int pos) {
	if(s==num)
		return true;
	bool sign= (le==0);
	for(int i=pos+1; i<n; i++) {
		if(vis[i])
			continue;
		if(le+sti[i] == l) {
			vis[i]=true;
			if(dfs(s+1, 0, -1))
				return true;
			vis[i]=false;
			return false;
		}
		else if(le+sti[i] < l){
			vis[i]=true;
			if(dfs(s, le+sti[i], i))
				return true;
			vis[i]=false;
			if(sign)
				return false;
			while(sti[i] == sti[i+1])
				i++;
		}
	}
	return false;
}

int main() {
	while(scanf("%d",&n), n) {
		init();
		sum=0;
		for(int i=0; i<n; i++){ 
			scanf("%d", &sti[i]);
			sum+=sti[i];
		}
		sort(sti, sti+n, cmp);
		
		for(l=sti[0]; l<=sum; l++) {
			if(sum%l != 0)
				continue;
			num=sum/l;
			memset(vis, 0, sizeof(vis));
			if(dfs(1, 0, -1)){
				printf("%d\n", l);
				break;
			}
		}
	}
	return 0;
}
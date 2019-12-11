#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num;
int n,m,p1,p2;
int fa[700];
int re[700];
int ind[1400];
int ans[700]; 
int dp[700][700];
int path[700][700];
int setn[700];

int find(int x){
	if(fa[x]==-1)
		return x;
	else {
		int tmp=fa[x];
		fa[x]=find(fa[x]);
		re[x]=(re[x]+re[tmp])%2;
		return fa[x];
	}
}

void bind(int u, int v, int d) {
	int x=find(u);
	int y=find(v);
	if(x != y) {
		fa[y]=x;
		re[y]=(2 + re[u] - re[v] +d)%2;
	}
}

int pack( ) {
	int k=0;
	for(int i=1; i<=n; i++)
		find(i);
	for(int i=1; i<=n; i++)
		if(fa[i]==-1)
			setn[k++]=i;
	for(int i=0; i<k; i++) {
		for(int j=ind[2*i]=1; j<=n; j++) {
			if(fa[j] == setn[i]) {
				if(re[j] == 0)
					ind[2*i]++;
				else
					ind[2*i+1]++;
			}
		}
	}
	dp[0][ind[0]]++;
	dp[0][ind[1]]++;
	path[0][ind[0]]=1;
	path[0][ind[1]]=2;
	
	for(int i=1; i<k; i++) {
		for(int j=p1; j>=0; j--) {
			if(j >= ind[2*i] && dp[i-1][j-ind[2*i]]) { 
				dp[i][j] += dp[i-1][j-ind[2*i]];
				path[i][j]=1;
			}
			if(j >= ind[2*i+1] && dp[i-1][j-ind[2*i+1]]) {
				dp[i][j] += dp[i-1][j-ind[2*i+1]];
				path[i][j]=2;
			} 
		}
	}
	
	if(dp[k-1][p1] != 1)
		return 0;
	int i=k-1;
	num=0;
	int m=p1;
	int t;
	while(i>=0) {
		if(path[i][m] == 1)
			t=0, m -= ind[2*i];
		if(path[i][m] == 2)
			t=1, m -= ind[2*i+1];
		for(int j=1; j<=n; j++)
			if(fa[j] == setn[i] || j == setn[i])
				if(re[j] == t)
					ans[num++] = j;
		i--;
	}
	sort(ans, ans+num);
	return 1;
}

void init( ) {
	memset(fa, -1, sizeof(fa));
	memset(re, 0, sizeof(re));
	memset(ind, 0, sizeof(ind));
	memset(ans, 0, sizeof(ans));
	memset(path, 0, sizeof(path));
	memset(setn, 0, sizeof(setn));
	memset(dp, 0, sizeof(dp));
}

int main() {
	while(scanf("%d%d%d",&m,&p1,&p2), m||p1||p2) {
		n=p1+p2;
		init( );
		int a,b,d;
		char c[10];
		for(int i=0; i<m; i++) {
			scanf("%d%d%s",&a, &b, c);
			if(a>b)
				swap(a, b);
			if(c[0]=='y')
				d=0;
			else
				d=1;
			bind(a, b, d);
		}
		if(p1 == p2) {
			printf("no\n");
			continue;
		}
		if(pack() == 0)
			printf("no\n");
		else {
			for(int i=0; i<num; i++)
				printf("%d\n", ans[i]);
			printf("end\n");
		}
	}
	return 0;
}
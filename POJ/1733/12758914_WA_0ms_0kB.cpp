#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int u;
	int v;
	int re;
};
int fa[5005];
int re[5005];
node q[5005];
int a[10005];

void init(int n) {
	for(int i=0; i<n; i++) {
		fa[i]=i;
		re[i]=0;
	}
}

int find(int x) {
	if(fa[x] == x) 
		return x;
	else{
		int tmp=fa[x];
		fa[x]=find(fa[x]);
		re[x]=(re[x] + re[tmp])%2;
		return fa[x];
	} 
}

int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF) {
		int cnt=0;
		for(int i=0; i<m; i++) {
			int u,v;
			char ch[5];
			scanf("%d%d%s",&u, &v, ch);
			u--;
			q[i].u=u;
			q[i].v=v;
			q[i].re= (ch[0] == 'e');
			a[cnt++]=u;
			a[cnt++]=v;
		}
		sort(a, a+cnt);
		cnt=unique(a, a+cnt) - a;
		init(cnt);
		int ans=m;
		for(int i=0; i<m; i++) {
			int u=lower_bound(a, a+cnt, q[i].u)-a;
			int v=lower_bound(a, a+cnt, q[i].v)-a;
			int r=q[i].re;
			int x=find(u);
			int y=find(v);
			if(x != y) {
				fa[y]=x;
				re[y]=(re[u] + r + 2 -re[v])%2;
			}
			if(x == y) {
				if(r !=(re[u] - re[v] + 2)%2){
					ans=i;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
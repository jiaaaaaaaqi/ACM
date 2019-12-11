#include<stdio.h>
#include<string.h>
#define N 50010

struct node
{
	int fath;
	int rela;
};
node ani[N];

int find(int x) {
	int tmp;
	if(ani[x].fath == x)
		return x;
	else {
		tmp = ani[x].fath;
		ani[x].fath == find(tmp);
		ani[x].rela = (ani[x].rela + ani[tmp].rela) % 3;
		return ani[x].fath;
	}
}

int main() {
	int n,m;
	int ans = 0;
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= n; i++) {
		ani[i].fath = i;
		ani[i].rela = 0;
	}
	while(m--) {
		int ca, u, v;
		scanf("%d%d%d",&ca, &u, &v);
		if(u<1 || v<1) {
			ans++;
			continue;
		}
		if(u>n || v>n) {
			ans++;
			continue;
		}
		int x = find(u);
		int y = find(v);
		if(x != y) {
			ani[y].fath = x;
			ani[y].rela = (3 + (ca-1) - ani[v].rela + ani[u].rela) % 3;
		}
		if(x == y) {
			int num = (ani[v].rela - ani[u].rela + 3) % 3;
			if(num != ca-1)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
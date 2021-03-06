#include<stdio.h>
#include<string.h>

struct node
{
	int fath;
	int rela;
};
node ani[50010];

int find(int x) {
	int temp;
	if(x == ani[x].fath)  
		return x;  
	temp = ani[x].fath;
	ani[x].fath == find(temp);
	ani[x].rela = (ani[x].rela + ani[temp].rela) % 3;
	return ani[x].fath;
}
/*int find(int x)
{
	int temp;  
	if(x == ani[x].fath)  
		return x;  
	temp = ani[x].fath; 
	ani[x].fath = find(temp);  
	ani[x].rela = (ani[x].rela + ani[temp].rela) % 3;
	return ani[x].fath;
} */ 

int main() {
	int n,m;
	int ans = 0;
	int ca, u, v;
	int x,y;
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= n; i++) {
		ani[i].fath = i;
		ani[i].rela = 0;
	}
	while(m--) {
		scanf("%d%d%d",&ca, &u, &v);
		if(u<1 || v<1) {
			ans++;
			continue;
		}
		if(u>n || v>n) {
			ans++;
			continue;
		}
		x = find(u);
		y = find(v);
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
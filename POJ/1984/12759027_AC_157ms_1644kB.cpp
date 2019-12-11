#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct node{
	int fath;
	int rex;
	int rey;
};
node q[40005];
struct node1{
	int u;
	int v;
	int time;
	int n;
};
node1 que[10005];
int ans[10005];
struct node2{
	int u;
	int v;
	int fx;
	int fy;
};
node2 way[40005];
int n,m,k;

void init() {
    memset(ans, 0, sizeof ans);
	for(int i=0; i<=n; i++) {
		q[i].fath=i;
		q[i].rex=0;
		q[i].rey=0;
	}

}

bool cmp(node1 a, node1 b) {
	return a.time < b.time;
}

int find(int x) {
	if(q[x].fath == x)
		return x;
	else {
		int tmp=q[x].fath;
		q[x].fath=find(q[x].fath);
		q[x].rex += q[tmp].rex;
		q[x].rey += q[tmp].rey;
		return q[x].fath;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	init();
	for(int i=0; i<m; i++) {
		int len;
		char dir;
		scanf("%d%d%d %c",&way[i].u, &way[i].v, &len, &dir);
		if(dir=='N')
			way[i].fx=-len, way[i].fy=0;
		else if(dir=='S')
			way[i].fx=len,  way[i].fy=0;
		else if(dir=='E')
			way[i].fx=0, way[i].fy=len;
		else if(dir=='W')
			way[i].fx=0, way[i].fy=-len;
	}

	scanf("%d", &k);
	for(int i=0; i<k; i++) {
		scanf("%d%d%d",&que[i].u, &que[i].v, &que[i].time);
		que[i].n=i;
	}
	sort(que, que+k, cmp);

	int cask=0;
	for(int i=0; i<=m; i++) {
		if(i==que[cask].time && cask<k) {
			int u=que[cask].u;
			int v=que[cask].v;
			int x=find(u);
			int y=find(v);
			if(x != y)
				ans[que[cask].n]=-1;
			else {
//				printf("x %d  %d\n",q[u].rex, q[u].rey);
//				printf("y %d  %d\n",q[v].rex, q[v].rey);
				int res=abs(q[u].rex-q[v].rex) + abs(q[u].rey-q[v].rey);
				ans[que[cask].n]=res;
			}
			cask++;
			i--;
		}
		else if(i<m){
			int u=way[i].u;
			int v=way[i].v;
			int x=find(u);
			int y=find(v);
			if(x != y) {
				q[y].fath = x;
				q[y].rex=q[u].rex - q[v].rex - way[i].fx;
				q[y].rey=q[u].rey - q[v].rey - way[i].fy;
			}
		}

	}
	for(int i=0; i<k; i++)
			printf("%d\n", ans[i]);
	return 0;
}

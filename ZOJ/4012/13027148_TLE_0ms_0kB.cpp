#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node{
	int x;
	int y;
	int c;
	int cnt;
};
Node node[100005];
Node edge[100005];

void init() {
	memset(node, 0, sizeof(node));
	memset(edge, 0, sizeof(edge));
}

bool hand(int i, int j) {
	if(edge[i].x < 0 )
		return true;
	if(edge[i].y < 0)
		return true;
	if(edge[i].x > node[j].x)
		return true;
	if(edge[i].y > node[j].y)
		return true;
	return false;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		init();
		int n,m;
		scanf("%d%d",&n, &m);
		for(int i=0; i<n; i++)
			scanf("%d%d",&edge[i].x, &edge[i].y);
		int maxx=0,maxy=0;
		for(int i=0; i<m; i++) {
			int a,b;
			scanf("%d%d",&a, &b);
			node[i].x=a;
			node[i].y=b;
			node[i].c=a*b;
			node[i].cnt=0;
			if(maxx<a)
				maxx=a;
			if(maxy<b)
				maxy=b;
		}
		for(int i=0; i<n; i++) {
			if(edge[i].x > maxx)
				continue;
			if(edge[i].y > maxy)
				continue;
			for(int j=0; j<m; j++) {
				if(hand(i, j))
					continue;
				if(edge[i].y*node[j].x + edge[i].x*node[j].y == node[j].c)
					node[i].cnt++;
			}
		}
		for(int i=0; i<m; i++)
			printf("%d\n",node[i].cnt);
	}
	return 0; 
}
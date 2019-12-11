#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Node{
	int x;
	int y;
	int cnt;
};
Node node[100005];
Node edge[100005];

void init() {
	memset(node, 0, sizeof(node));
	memset(edge, 0, sizeof(edge));
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
		for(int i=0; i<m; i++)
			scanf("%d%d",&node[i].x, &node[i].y);
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				long long int a=edge[i].x * node[j].y;
				long long int b=(node[j].y - edge[i].y) * node[j].x;
				if(a == b)
					node[j].cnt++;
			}
		}
		for(int i=0; i<m; i++)
			printf("%d\n",node[i].cnt);
	}
	return 0; 
}
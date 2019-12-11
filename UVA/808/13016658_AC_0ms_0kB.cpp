#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<algorithm>

using namespace std;

struct Node {
	int x;
	int y;
};
Node node[15005];
int dir[6][2]= {{-1,1}, {0,2}, {1,1}, {1,-1}, {0,-2}, {-1,-1}};

void handle() {
	int cnt=1;
	int x=0;
	int y=0;

	node[cnt].x=x;
	node[cnt++].y=y;

	y-=2;
	node[cnt].x=x;
	node[cnt++].y=y;
	for(int k=1; k<=60; k++) {
		for(int i=0; i<5; i++) {
			for(int j=0; j<k; j++) {
				x+=dir[i][0];
				y+=dir[i][1];
				node[cnt].x=x;
				node[cnt++].y=y;
			}
		}

		y-=2;
		node[cnt].x=x;
		node[cnt++].y=y;
		for(int j=0; j<k; j++) {
			x+=dir[5][0];
			y+=dir[5][1];
			node[cnt].x=x;
			node[cnt++].y=y;
		}
	}
}
int main() {
	memset(node, 0, sizeof(node));
	int be,en;
	handle();
	while(scanf("%d%d",&be, &en), be||en) {
		int bex=node[be].x;
		int bey=node[be].y;
		int enx=node[en].x;
		int eny=node[en].y;
		int x=abs(node[be].x - node[en].x);
		int y=abs(node[be].y - node[en].y);
		int ans;
		if(x>y)
			ans=x;
		else
			ans=x+(y-x)/2;
		printf("The distance between cells %d and %d is %d.\n",be,en,ans);
	}
	return 0;
}
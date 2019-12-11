#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 0x3f3f3f3f

using namespace std;

int n;
char str[35][100];
double maps[35][35];

void init() {
	memset(maps, 0, sizeof(maps));
	memset(str, 0, sizeof(str));
}

bool Floyed() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(maps[i][j] < maps[i][k] * maps[k][j]) {
					maps[i][j] = maps[i][k] * maps[k][j];
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(maps[i][i] > 1)
			return true;
	return false;		
}

int main() {
	int m;
	int cas=1;
	while(scanf("%d",&n), n) {
		init();
		for(int i=1; i<=n; i++)
			maps[i][i] = 1;
		for(int i=1; i<=n; i++) {
			scanf("%s",str[i]);
		}
		scanf("%d",&m);
		char str1[100];
		char str2[100];
		int a,b;
		double c;
		for(int i=1; i<=m; i++) {
			int flag;
			memset(str1, 0, sizeof(str1));
			memset(str2, 0, sizeof(str2));
			scanf("%s %lf %s",str1, &c, str2);
			flag=0;
			for(int j=1; j<=n; j++){
				if(flag==2)
					break;
				if(strcmp(str1, str[j]) == 0) {
					flag++; 
					a=j;
				}
				if(strcmp(str2, str[j]) == 0) {
					flag++;
					b=j;
				}
			}
			if(flag != 2)
				continue;
			else {
				maps[a][b] = c;
			}
		}
		bool ans=Floyed();	
/*
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				printf("%lf%c",maps[i][j], j==n ? '\n':'\t');
*/
		printf("Case %d: %s\n",cas++, ans ? "Yes":"No");
	}
	return 0; 
}
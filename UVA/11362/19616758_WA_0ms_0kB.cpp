#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int tree[15000*10][15];
int flag[15000];
char str[101];
int mark;
int cnt;

void insert()
{
	int len = strlen(str);
	int id;
	int u = 0;
	for(int i=0; i<len; i++)
	{
		id = str[i] - '0';
		int no = tree[u][id];
		if(flag[no])
			mark = 1;
		if(i == len-1&&tree[u][id])
			mark = 1;
		if(!tree[u][id])
		{
			tree[u][id] = ++cnt;
		}
		u = tree[u][id];
	}
	flag[u] = 1;
}

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	memset(tree, 0, sizeof(tree));
	memset(flag, 0, sizeof(flag));
	while(T--)
	{
		cnt = 0; 
		mark = 0;
		int N;
		scanf("%d",&N);
		while(N--)
		{
			scanf("%s",str);
			insert();
		}
		if(!mark)
			printf("YES\n");
		else
			printf("NO\n");
		memset(tree, 0, sizeof(tree));
		memset(flag, 0, sizeof(flag));
		mark = 0;
	}
	return 0;
}
/*************************************************************** 
  > File Name    : a.cpp
  > Author       : Jiaaaaaaaqi
  > Created Time : Mon 14 Oct 2019 07:20:55 PM CST
 ***************************************************************/

#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, szeof a)
#define  fi         first
#define  se         second
#define  pb         push_back
#define  pii        pair<int, int>

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Splay {

#define ls(x) T[x].ch[0]
#define rs(x) T[x].ch[1]
#define fa(x) T[x].fa
#define root T[0].ch[1]
	struct node
	{
		int fa,ch[2],val,rec,sum;
		int id;
	}T[maxn];
	int tot,pointnum;
	void init() {
		tot = pointnum = 0;
	}
	void update(int x){T[x].sum=T[ls(x)].sum+T[rs(x)].sum+T[x].rec;}
	int ident(int x){return T[fa(x)].ch[0]==x?0:1;}
	void connect(int x,int fa,int how){T[fa].ch[how]=x;T[x].fa=fa;}
	void rotate(int x)
	{
		int Y=fa(x),R=fa(Y);
		int Yson=ident(x),Rson=ident(Y);
		connect(T[x].ch[Yson^1],Y,Yson);
		connect(Y,x,Yson^1);
		connect(x,R,Rson);
		update(Y);update(x);
	}
	void splay(int x,int to)
	{
		to=fa(to);
		while(fa(x)!=to)
		{
			int y=fa(x);
			if(T[y].fa==to) rotate(x);
			else if(ident(x)==ident(y)) rotate(y),rotate(x);
			else rotate(x),rotate(x);
		}
	}
	int newnode(int v,int f)
	{
		T[++tot].fa=f;
		T[tot].rec=T[tot].sum=1;
		T[tot].val=v;
		return tot;
	}
	void insert(int x, int id)
	{
		int now=root;
		if(root==0) {
			root = newnode(x,0);
			T[root].id = id;
		}//
		else
		{
			while(1)
			{
				T[now].sum++;
				if(T[now].val==x) {T[now].rec++;splay(now,root);return ;}
				int nxt=x<T[now].val?0:1;
				if(!T[now].ch[nxt])
				{
					int p=newnode(x,now);
					T[p].id = id;
					T[now].ch[nxt]=p;
					splay(p,root);
					return ;
				}
				now=T[now].ch[nxt];
			}       
		}
	}
	int find(int x)
	{
		int now=root;
		while(1)
		{
			if(!now) return 0;
			if(T[now].val==x) {splay(now,root);return now;}
			int nxt=x<T[now].val?0:1;
			now=T[now].ch[nxt];
		}
	}
	void del(int x)
	{
		int pos=find(x);
		if(!pos) return ;
		if(T[pos].rec>1) {T[pos].rec--,T[pos].sum--;return ;} 
		else
		{
			if(!T[pos].ch[0]&&!T[pos].ch[1]) {root=0;return ;}
			else if(!T[pos].ch[0]) {root=T[pos].ch[1];T[root].fa=0;return ;}
			else
			{
				int left=T[pos].ch[0];
				while(T[left].ch[1]) left=T[left].ch[1];
				splay(left,T[pos].ch[0]);
				connect(T[pos].ch[1],left,1); 
				connect(left,0,1);//
				update(left);
			}
		}
	}
	int rak(int x)
	{
		int now=root,ans=0;
		while(1)
		{
			if(T[now].val==x) return ans+T[T[now].ch[0]].sum+1;
			int nxt=x<T[now].val?0:1;
			if(nxt==1) ans=ans+T[T[now].ch[0]].sum+T[now].rec;
			now=T[now].ch[nxt];
		}
	}
	int kth(int x)//排名为x的数 
	{
		int now=root;
		while(1)
		{
			int used=T[now].sum-T[T[now].ch[1]].sum;
			if(T[T[now].ch[0]].sum<x&&x<=used) {splay(now,root);return T[now].val;}
			if(x<used) now=T[now].ch[0];
			else now=T[now].ch[1],x-=used;
		}
	}
	int lower(int x)
	{
		int now=root,ans=-inf;
		while(now)
		{
			if(T[now].val<x) ans=max(ans,T[now].val);
			int nxt=x<=T[now].val?0:1;//这里需要特别注意 
			now=T[now].ch[nxt];
		}
		return ans;
	}
	int upper(int x)
	{
		int now=root,ans=inf;
		while(now)
		{
			if(T[now].val>x) ans=min(ans,T[now].val);
			int nxt=x<T[now].val?0:1;
			now=T[now].ch[nxt];
		}
		return ans;
	}

	void highest() {
		if(root == 0) {
			printf("0\n");
		} else {
			int x = root;
			while(T[x].ch[1])	x = T[x].ch[1];
			printf("%d\n", T[x].id);
			del(T[x].val);
		}
	}
	void lowest() {
		if(root == 0) {
			printf("0\n");
		} else {
			int x = root;
			while(T[x].ch[0])	x = T[x].ch[0];
			printf("%d\n", T[x].id);
			del(T[x].val);
		}
	}
} splay;

// void highest() {
//     if(splay.rt == 0) {
//         printf("0\n");
//     } else {
//         int x = splay.rt;
//         while(splay.ch[x][1])	x = splay.ch[x][1];
//         printf("%d\n", splay.id[x]);
//         splay.del(splay.val[x]);
//     }
// }
// void lowest() {
//     if(splay.rt == 0) {
//         printf("0\n");
//     } else {
//         int x = splay.rt;
//         while(splay.ch[x][0])	x = splay.ch[x][0];
//         printf("%d\n", splay.id[x]);
//         splay.del(splay.val[x]);
//     }
// }


int main() {
	// freopen("in", "r", stdin);
	splay.init();
	while(scanf("%d", &m), m) {
		if(m == 1) {
			int k, p;
			scanf("%d%d", &k, &p);
			splay.insert(p, k);
		} else if(m == 2) {
			splay.highest();
		} else if(m == 3) {
			splay.lowest();
		} else	break;
	}
	return 0;
}

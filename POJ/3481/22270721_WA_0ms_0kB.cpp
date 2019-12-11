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
using namespace std;

const int maxn = 1e5 + 5;
const int inf  = 0x3f3f3f3f;

struct Splay {
	int root, tot;
	int sz[maxn], cnt[maxn], pre[maxn], val[maxn], ch[maxn][2], id[maxn];
	//由于这里我们用到了l - 1和r + 1号节点，所以对于节点1 ~ n的，如果查询1 ~ n这个区间，
	//就会用到0, n + 1这两个节点，所以开始建树时要多加入两个节点。
	void init() {
		root = tot = 0;
		insert(-inf, 0);
		insert(inf, 0);
	} 
	 
	void pushup(int x) {
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
	}
	 
	int get(int x) {
		return ch[pre[x]][1] == x;//1为右, 0为左
	}
	 
	void rotate(int x) {
		int f = pre[x], gf = pre[f], k = get(x), w = ch[x][k ^ 1];
		ch[f][k] = w, pre[w] = f;
		ch[gf][get(f)] = x, pre[x] = gf;
		ch[x][k ^ 1] = f, pre[f] = x;
		pushup(f), pushup(x);//先pushup下面的节点! 
	}
	 
	void splay(int x, int goal = 0) {//不传goal, 说明旋转成根节点
		int f, gf;
		while (pre[x] != goal) {
			f = pre[x], gf = pre[f];
			if (gf != goal) {
				if(get(x) == get(f)) rotate(f);
				else rotate(x);
			}
			rotate(x);
		}
		if (!goal) root = x;
	}
	 
	void insert(int x, int d) {//cur是节点编号, 树上都是按编号操作, 不是按权值操作
		int cur = root, f = 0;
		while (cur && val[cur] != x) {
			f = cur;
			cur = ch[cur][x > val[cur]];
		}
		if (cur) {
			cnt[cur]++;
		} else {
			cur = ++tot;
			if (f) ch[f][x > val[f]] = cur;
			ch[cur][0] = ch[cur][1] = 0;
			sz[cur] = cnt[cur] = 1;
			pre[cur] = f, val[cur] = x;
			id[cur] = d;
		}
		splay(cur);
	}
	 
	void change(int x) {//寻找最大的比这个节点小或等于的节点，并将其splay至根节点
		if (!root) return ;
		int cur = root;
		while(ch[cur][x > val[cur]] && val[cur] != x) 
			cur = ch[cur][x > val[cur]];
		splay(cur);
	}
	 
	int getpre(int x) {
		change(x);
		if (x > val[root]) return root;
		int cur = ch[root][0];
		while (ch[cur][1]) cur = ch[cur][1];
		return cur;
	}
	 
	int getsuc(int x) {
		change(x);
		if (x < val[root]) return root;
		int cur = ch[root][1];
		while (ch[cur][0]) cur = ch[cur][0];
		return cur;
	}
	 
	void del(int x) {
		int pre = getpre(x), suc = getsuc(x);
		splay(pre), splay(suc, pre);
		int cur = ch[suc][0];
		if (cnt[cur] > 1) {
			cnt[cur]--;
			splay(cur);
		} else {
			ch[suc][0] = 0;
		  pushup(suc), pushup(root);
		}
	}
	 
	int kth(int x) {
		int cur = root;
		while (true) {
			if (sz[ch[cur][0]] >= x && ch[cur][0]) {
				cur = ch[cur][0];
			} else {
				x -= sz[ch[cur][0]] + cnt[cur];
				if (x <= 0) return cur;
				cur = ch[cur][1];
			}
		}
	}
 
	void high() {
		int x = root;
		if(sz[x] == 2) {
			printf("0\n");
		} else {
			while(val[ch[x][1]] != inf)	x = ch[x][1];
			printf("%d\n", id[x]);
			del(val[x]);
		}
	}
	void low() {
		int x = root;
		if(sz[x] == 2) {
			printf("0\n");
		} else {
			while(val[ch[x][0]] != -inf)	x = ch[x][0];
			printf("%d\n", id[x]);
			del(val[x]);
		}
	}
} splay;

int main() {
	// freopen("in", "r", stdin);
	int op;
	splay.init();
	while(scanf("%d", &op), op) {
		if(op == 1) {
			int k, p;
			scanf("%d%d", &k, &p);
			splay.insert(p, k);
		} else if(op == 2) {
			splay.high();
		} else if(op == 3) {
			splay.low();
		} else	break;
	}
	return 0;
}

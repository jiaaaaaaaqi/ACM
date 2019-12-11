int root, tot;
int ch[maxn][2];
int sz[maxn], fa[maxn], val[maxn], cnt[maxn], id[maxn], rev[maxn];
int a[maxn];
// 所谓哨兵节点，就是在操作的 [l, r] 区间的时候，需要用到 l-1 和 r+1 节点
// 为了数组不越界，则在一开始序列的首尾各插入一个用不上的数字

void init() {
	root = tot = 0;
} 

int newnode(int x, int f) {
	mes(ch[++tot], 0);
	fa[tot] = f;
	val[tot] = x;
	rev[tot] = 0;
	sz[tot] = cnt[tot] = 1;
	if(abs(x) != inf)	id[x] = tot;
	return tot;
}

// 凡是打过标记以后的操作，每次都得 pushdown 一下
// 每次 pushdown 的时候都要先判断是否存在左右节点
void pushdown(int x) {
	if(x) {
		if(rev[x]) {
			swap(ch[x][0], ch[x][1]);
			if(ch[x][0])	rev[ch[x][0]] ^= 1;
			if(ch[x][1])	rev[ch[x][1]] ^= 1;
			rev[x] = 0;
		}
	}
}

// 一定要 pushup 到 root
//如果插入在最左或者最右，应该从 root 开始递归插入，回溯时pushup
void pushup(int x) {
	if(x) {
		sz[x] = cnt[x];
		if(ch[x][0])	sz[x] += sz[ch[x][0]];
		if(ch[x][1])	sz[x] += sz[ch[x][1]];
	}
}

// 1为右, 0为左
int get(int x) {
	return ch[fa[x]][1] == x;
}

void rotate(int x) {
	int f = fa[x], gf = fa[f], k = get(x), w = ch[x][k ^ 1];
	pushdown(f), pushdown(x);// 不能 pushdown gf！
	ch[f][k] = w, fa[w] = f;
	ch[gf][get(f)] = x, fa[x] = gf;
	ch[x][k ^ 1] = f, fa[f] = x;
	pushup(f), pushup(x);// 先pushup下面的节点! 
}

// 把 x 翻转成 goal 的子节点
// 不传goal, 说明旋转成根节点
void splay(int x, int goal = 0) {
	int f, gf;
	while (fa[x] != goal) {
		f = fa[x], gf = fa[f];
		pushdown(gf), pushdown(f), pushdown(x);
		if (gf != goal) {
			if(get(x) == get(f)) rotate(f);
			else rotate(x);
		}
		rotate(x);
	}
	if (!goal) root = x;
}

// 查看正在维护的序列
void ViewTree(int x) {
	pushdown(x);
	if(ch[x][0])	ViewTree(ch[x][0]);
	printf("%d ", val[x]);
	if(ch[x][1])	ViewTree(ch[x][1]);
}

// 当前第 x 个数的位置
int kth(int x) {
	int cur = root;
	while (true) {
		pushdown(cur);
		if (sz[ch[cur][0]] >= x && ch[cur][0]) {
			cur = ch[cur][0];
		} else {
			x -= sz[ch[cur][0]] + cnt[cur];
			if (x <= 0) return cur;
			cur = ch[cur][1];
		}
	}
}

// 类似线段树的递归建树
int build(int l, int r, int f) {
	if(l > r)	return 0;
	int mid = l+r>>1;
	int now = newnode(a[mid], f);
	ch[now][0] = build(l, mid-1, now);
	ch[now][1] = build(mid+1, r, now);
	pushup(now);
	return now;
}
root = build(1, n, 1);

// 切割 [l, r] 区间并放到切割后的第 k 个数后
void CUT(int x, int y, int k) {	
	int tmp;
	{
		x = kth(x-1), y = kth(y+1);
		splay(x), splay(y, x);
		int cur = ch[root][1];
		tmp = ch[cur][0];
		ch[cur][0] = 0;
		pushup(cur), pushup(root);
	}
	{
		x = kth(k), y = kth(k+1);
		splay(x), splay(y, x);
		int cur = ch[root][1];
		ch[cur][0] = tmp, fa[tmp] = cur;
		pushup(cur), pushup(root);
	}
	splay(tmp);
}

// 翻转 [l, r] 区间
void reverse(int l, int r) {
	int x = kth(l-1), y = kth(r+1);
	splay(x), splay(y, x);	// 此时 root 的右子树的左子树就是 [l, r] 区间
	int cur = ch[root][1];
	rev[ch[cur][0]] ^= 1;
	pushup(cur), pushup(root);
}

//递归插入一个数，一般适用于插入在某棵树的最左或最右位置
void insert(int &rt, int k, int f) {
	if(rt == 0) {
		rt = newnode(k, f);
		pushup(rt);
		return ;
	}
	insert(ch[rt][0], k, rt);
	pushup(rt);
}

// 在第 k 个数字后面插入数字x
void Insert(int k, int d) {
	int x = kth(k), y = kth(k+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	ch[cur][0] = newnode(d, cur);
	pushup(cur), pushup(root);
	splay(tot);
}

// 删除第 k 个数
void del(int k) {
	int x = kth(k-1), y = kth(k+1);
	splay(x), splay(y, x);
	int cur = ch[root][1];
	ch[cur][0] = 0;
	pushup(cur), pushup(root);
}

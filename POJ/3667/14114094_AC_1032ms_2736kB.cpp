#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
const int inf = 0x3f3f3f3f;
const int maxn = 50005;
const int mod = 10007;

int n, m;
int lsum[maxn << 2];
int rsum[maxn << 2];
int asum[maxn << 2];
int lazy[maxn << 2];

void init() {
	memset(lsum, 0, sizeof(lsum));
	memset(rsum, 0, sizeof(rsum));
	memset(asum, 0, sizeof(asum));
	memset(lazy, 0, sizeof(lazy));
}

void pushdown(int root, int lnum, int rnum) {
	if(lazy[root] != -1) {
		lazy[root << 1] = lazy[root << 1 | 1] = lazy[root];
		lsum[root << 1] = rsum[root << 1] = asum[root << 1] = lazy[root] ? 0 : lnum;
		lsum[root << 1 | 1] = rsum[root << 1 | 1] = asum[root << 1 | 1] = lazy[root] ? 0 : rnum;
		lazy[root] = -1;
	}
	return ;
}

void pushup(int root, int lnum, int rnum) {
	lsum[root] = lsum[root << 1];
	rsum[root] = rsum[root << 1 | 1];
	if(lsum[root] == lnum)
		lsum[root] += lsum[root << 1 | 1];
	if(rsum[root] == rnum)
		rsum[root] += rsum[root << 1];
	asum[root] = max(max(asum[root << 1], asum[root << 1 | 1]), rsum[root << 1] + lsum[root << 1 | 1]);
}

void build(int left, int right, int root) {
	lsum[root] = rsum[root] = asum[root] = right - left + 1;
	if(left == right) {
		return ;
	}
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
	pushup(root, mid - left + 1, right - mid);
}

void update(int left, int right, int prel, int prer, int root, int val) {
	if(prel <= left && right <= prer) {
		lazy[root] = val;
		lsum[root] = rsum[root] = asum[root] = val ? 0 : (right - left + 1);
		return ; 
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left +1, right - mid);
	if(prel <= mid)
		update(left, mid, prel, prer, root << 1, val);
	if(prer > mid)
		update(mid + 1, right, prel, prer, root << 1 | 1, val);
	pushup(root, mid - left + 1, right - mid);
}

int query(int left, int right, int root, int len) {
	if(left == right) {
		return left;
	}
	int mid = (left + right) >> 1;
	pushdown(root, mid - left + 1, right - mid);
	if(asum[root << 1] >= len)
		return query(left, mid, root << 1, len);
	else if(rsum[root << 1] + lsum[root << 1 | 1] >= len)
		return mid - rsum[root << 1] + 1;
	else
		return query(mid + 1, right, root << 1 | 1, len);
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		build(1, n, 1);
		while(m--) {
			int id;
			scanf("%d", &id);
			if(id == 1) {
				int num;
				scanf("%d", &num);
				if(asum[1] < num) {
					printf("0\n");
					continue;
				}
				int pos = query(1, n, 1, num);
				printf("%d\n", pos);
				update(1, n, pos, pos + num - 1, 1, 1);
			} else if(id == 2) {
				int pos, num;
				scanf("%d%d", &pos, &num);
				update(1, n, pos, pos + num - 1, 1, 0);
			}
		}
	}
	return 0;
} 
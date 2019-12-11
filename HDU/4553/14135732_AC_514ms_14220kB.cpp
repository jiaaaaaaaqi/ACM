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

typedef unsigned long long int ull;
typedef long long int ll;
const double pi = 4.0*atan(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 100005;
using namespace std;

int n, m;
int lsumd[maxn << 2], rsumd[maxn << 2], msumd[maxn << 2];
int lsums[maxn << 2], rsums[maxn << 2], msums[maxn << 2];
int lazyd[maxn << 2], lazys[maxn <<2];

void init() {
	memset(lsumd, 0, sizeof(lsumd));
	memset(rsumd, 0, sizeof(rsumd));
	memset(msumd, 0, sizeof(msumd));
	memset(lsums, 0, sizeof(lsums));
	memset(rsums, 0, sizeof(rsums));
	memset(msums, 0, sizeof(msums));
	memset(lazyd, -1, sizeof(lazyd));
	memset(lazys, -1, sizeof(lazys));
}

void build(int left, int right, int root) {
	lsumd[root] = rsumd[root] = msumd[root] = right - left + 1;
	lsums[root] = rsums[root] = msums[root] = right - left + 1;
	if(left == right)	return;
	int mid = (left + right) >> 1;
	build(left, mid, root << 1);
	build(mid + 1, right, root << 1 | 1);
}

void pushupd(int root, int lnum, int rnum) {
	lsumd[root] = lsumd[root << 1];
	rsumd[root] = rsumd[root << 1 | 1];
	if(lsumd[root] == lnum)		lsumd[root] += lsumd[root << 1 | 1];
	if(rsumd[root] == rnum)		rsumd[root] += rsumd[root << 1];
	msumd[root] = max(rsumd[root << 1] + lsumd[root << 1 | 1], max(msumd[root << 1], msumd[root << 1 | 1]));
}

void pushups(int root, int lnum, int rnum) {
	lsums[root] = lsums[root << 1];
	rsums[root] = rsums[root << 1 | 1];
	if(lsums[root] == lnum)		lsums[root] += lsums[root << 1 | 1];
	if(rsums[root] == rnum)		rsums[root] += rsums[root << 1];
	msums[root] = max(rsums[root << 1] + lsums[root << 1 | 1], max(msums[root << 1], msums[root << 1 | 1]));
}

void pushdownd(int root, int lnum, int rnum) {
	if(lazyd[root] != -1) {
		lazyd[root << 1] = lazyd[root << 1 | 1] = lazyd[root];
		lsumd[root << 1] = rsumd[root << 1] = msumd[root << 1] = lazyd[root] ? 0 : lnum;
		lsumd[root << 1 | 1] = rsumd[root << 1 | 1] = msumd[root << 1 | 1] = lazyd[root] ? 0 : rnum;
		lazyd[root] = -1;
	}
	return ;
}

void pushdowns(int root, int lnum, int rnum) {
	if(lazys[root] != -1) {
		lazys[root << 1] = lazys[root << 1 | 1] = lazys[root];
		lsums[root << 1] = rsums[root << 1] = msums[root << 1] = lazys[root] ? 0 : lnum;
		lsums[root << 1 | 1] = rsums[root << 1 | 1] = msums[root << 1 | 1] = lazys[root] ? 0 : rnum;
		lazys[root] = -1;
	}
	return ;
}

void updated(int left, int right, int prel, int prer, int root, int val) {
	if(prel <= left && right <= prer) {
		lazyd[root] = val;
		lsumd[root] = rsumd[root] = msumd[root] = val ? 0 : right - left + 1;
		return;
	}
	int mid = (left + right) >> 1;
	pushdownd(root, mid - left + 1, right - mid);
	if(prel <= mid)		updated(left, mid, prel, prer, root << 1, val);
	if(prer > mid)		updated(mid + 1, right, prel, prer, root << 1 | 1, val);
	pushupd(root, mid - left + 1, right - mid);
	return ;
}

void updates(int left, int right, int prel, int prer, int root, int val) {
	if(prel <= left && right <= prer) {
		lazys[root] = val;
		lsums[root] = rsums[root] = msums[root] = val ? 0 : right - left + 1;
		return ;
	}
	int mid = (left + right) >> 1;
	pushdowns(root, mid - left + 1, right - mid);
	if(prel <= mid)		updates(left, mid, prel, prer, root << 1, val);
	if(prer > mid)		updates(mid + 1, right, prel, prer, root << 1 | 1, val);
	pushups(root, mid - left + 1, right - mid);
	return ;
}

int queryd(int left, int right, int root, int num) {
	if(left == right)	return left;
	int mid = (left + right) >> 1;
	pushdownd(root, mid - left + 1, right - mid);
	if(msumd[root << 1] >= num)		return queryd(left, mid, root << 1, num);
	else if(rsumd[root << 1] + lsumd[root << 1 | 1] >= num)		return mid - rsumd[root << 1] + 1;
	else	return queryd(mid + 1, right, root << 1 | 1, num);
}

int querys(int left, int right, int root, int num) {
	if(left == right)	return left;
	int mid = (left + right) >> 1;
	pushdowns(root, mid - left + 1, right - mid);
	if(msums[root << 1] >= num)		return querys(left, mid, root << 1, num);
	else if(rsums[root << 1] + lsums[root << 1 | 1] >= num)		return mid - rsums[root << 1] + 1;
	else	return querys(mid + 1, right, root << 1 | 1, num);
}

int main() {
	int T;
	scanf("%d", &T);
	int cas = 1;
	while(T--) {
		init();
		printf("Case %d:\n", cas++);
		scanf("%d%d", &n, &m);
		build(1, n, 1);
		char str[15];
		while(m--) {
			scanf("%s", str);
			if(str[0] == 'D') {
				int num;
				scanf("%d", &num);
				if(msumd[1] < num)	{
					printf("fly with yourself\n");
					continue;
				} else {
					int pos = queryd(1, n, 1, num);
					printf("%d,let's fly\n", pos);
					updated(1, n, pos, pos + num - 1, 1, 1);
				}
			} else if(str[0] == 'N') {
				int num;
				scanf("%d", &num);
				if(msumd[1] >= num) {
					int pos = queryd(1, n, 1, num);
					printf("%d,don't put my gezi\n",pos);
					updated(1, n, pos, pos + num - 1, 1, 1);
					updates(1, n, pos, pos + num - 1, 1, 1);
				} else if(msums[1] >= num) {
					int pos = querys(1, n, 1, num);
					printf("%d,don't put my gezi\n",pos);
					updated(1, n, pos, pos + num - 1, 1, 1);
					updates(1, n, pos, pos + num - 1, 1, 1);
				} else {
					printf("wait for me\n");
				}
			} else if(str[0] == 'S') {
				int prel, prer;
				scanf("%d%d", &prel, &prer);
				updated(1, n, prel, prer, 1, 0);
				updates(1, n, prel, prer, 1, 0);
				printf("I am the hope of chinese chengxuyuan!!\n");
			}
		}
	}
	return 0;
}

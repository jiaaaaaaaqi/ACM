#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#define  Mid    (tree[id].l + tree[id].r)>>1
#define  lson   id<<1
#define  rson   id<<1|1
typedef long long LL;
using namespace std;
 
const int inf = 0x3f3f3f3f;
const int maxn = 4e5+5;
 
struct node{
    int l, r;
    LL ml, rl, ll;
    void set(int L, int R){
        l = L, r = R;
    }
}Htree[maxn<<2], Wtree[maxn<<2];
struct node2{
    int id, x;
}que[maxn];
LL W[maxn];///长
LL H[maxn];///高
 
 
void build(node tree[], int id, int l, int r, int k) {
    tree[id].set(l, r);
    if(l == r) {
        if(k == 0) {
            tree[id].ml = tree[id].rl = tree[id].ll = W[tree[id].r]- W[tree[id].l-1];
            //cout << "W   ";
        }
        else {
            tree[id].ml = tree[id].rl = tree[id].ll = H[tree[id].r]- H[tree[id].l-1];
            //cout << "H   ";
        }
        //cout << l << ' ' << r << ' ' << id << ' ' << tree[id].ml << endl;
        return ;
    }
    int mid = Mid;
    build(tree, lson, l, mid, k);
    build(tree, rson, mid+1, r, k);
    tree[id].ml = tree[id].ll = tree[id].rl = tree[lson].ml + tree[rson].ml;
    //cout << l << ' ' << r << ' ' << id << ' ' << tree[id].ml << endl;
}
 
void pushup(node tree[], int id) {
    int mid = Mid;
    tree[id].ll = tree[lson].ll;
    tree[id].rl = tree[rson].rl;
    tree[id].ml = max(tree[lson].ml, tree[rson].ml);
    tree[id].ml = max(tree[id].ml, tree[lson].rl + tree[rson].ll);
 
    if(tree[lson].ll == mid - tree[id].l + 1)
        tree[id].ll += tree[rson].ll;
    if(tree[rson].rl == tree[id].r - mid + 1)
        tree[id].rl += tree[lson].rl;
}
 
void update(node tree[], int id, int x) {
    if(tree[id].l == x && tree[id].r == x) {
        tree[id].ml = tree[id].ll = tree[id].rl = 0;
        return ;
    }
    int mid = Mid;
    if(x <= mid)    update(tree, lson, x);
    else update(tree, rson, x);
    pushup(tree, id);
}
 
int divide(LL arr[], int l, int r, int v) {   ///二分查找下标
    int L, R;
    L = l, R = r;
    while(R >= L) {
        int mid = (L + R) >> 1;
        if(arr[mid] == v)    return mid;
        if(arr[mid] > v)     R = mid-1;
        else                L = mid+1;
    }
    return -1;
}
 
 
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, Q, n1, n2;
        n1 = n2 = 0;
        scanf("%d%d%d", &n, &m, &Q);
        for(int i = 1; i <= Q; ++i) {
            scanf("%d%d", &que[i].id, &que[i].x);
            if(que[i].x == 0)   continue;
            if(que[i].id == 0) {
                if(que[i].x == n)   continue;
                W[++n1] = que[i].x;
                if(que[i].x > 0)    W[++n1] = que[i].x - 1;
                if(que[i].x < n-1)    W[++n1] = que[i].x + 1;
            }else {
                if(que[i].x == m)   continue;
                H[++n2] = que[i].x;
                if(que[i].x > 0)    H[++n2] = que[i].x - 1;
                if(que[i].x < m-1)    H[++n2] = que[i].x + 1;
            }
        }
        W[++n1] = n - 1;
        H[++n2] = m - 1;
        sort(W+1, W + n1+1);///水平的
        sort(H+1, H + n2+1);///竖直的
 
        int k = 1;
        for(int i = 2; i <= n1; ++i)
            if(W[i] != W[i-1])
                W[++k] = W[i];
        n1 = k;
        k = 1;
        for(int i = 2; i <= n2; ++i)
            if(H[i] != H[i-1])
                H[++k] = H[i];
        n2 = k;
 
        build(Wtree, 1, 1, n1, 0);
        build(Htree, 1, 1, n2, 1);
 
        LL res;
        for(int i = 1; i <= Q; ++i) {
            int x;
            if(que[i].id == 0) { ///水平的
                if(que[i].x != 0 && que[i].x != n) {
                    x = divide(W, 1, n1, que[i].x);
                    update(Wtree, 1, x);
                }
            }else{///竖直的
                if(que[i].x != 0 && que[i].x != m) {
                    x = divide(H, 1, n2, que[i].x);
                    update(Htree, 1, x);
                }
            }
            res = (Htree[1].ml + 1)*(Wtree[1].ml+1);
            printf("%lld\n", res);
        }
    }
 
 
 
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 10;
int a[mx], b[mx], ans;

bool judge(int x[], int y[]) {
    for (int i = 1; i <= 6; i++)
        if (x[i] != y[i]) return false;
    return true;
}

void change(int c[], int op) {
    op++;
    int d[10];
    for (int i = 1; i <= 6; i++) d[i] = c[i];
    if (op == 1) {
        c[1] = d[6];
        c[2] = d[5];
        c[5] = d[1];
        c[6] = d[2];
    }
    if (op == 2) {
        c[1] = d[5];
        c[2] = d[6];
        c[5] = d[2];
        c[6] = d[1];
    }
    /*
    if (op == 3) {
        c[3] = d[5];
        c[4] = d[6];
        c[5] = d[4];
        c[6] = d[3];
    }
    if (op == 4) {
        c[3] = d[6];
        c[4] = d[5];
        c[5] = d[3];
        c[6] = d[4];
    }*/
    if (op == 3) {
        c[1] = d[4];
        c[2] = d[3];
        c[3] = d[1];
        c[4] = d[2];
    }
    if (op == 4) {
        c[1] = d[3];
        c[2] = d[4];
        c[3] = d[2];
        c[4] = d[1];
    }
}

void dfs(int c[], int deep) {
    

    if (judge(c, b)) {
        /*
        printf("*******\n");
        for (int j = 1; j <= 6; j++) printf("%d%c", c[j], j==6?'\n':' ');
        */
        ans = min(ans, deep);
        return ;
    }

    if (deep > ans || deep >= 10) return ;

    for (int i = 0; i < 4; i++) {
        //for (int j = 1; j <= 6; j++) printf("%d%c", c[j], j==6?'\n':' ');
        //printf("i = %d\n", i);
        change(c, i);
        //for (int j = 1; j <= 6; j++) printf("%d%c", c[j], j==6?'\n':' ');
        dfs(c, deep+1);
        change(c, i^1);
    }
}

int main() {
    while (scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) != EOF) {
        scanf("%d%d%d%d%d%d", &b[1], &b[2], &b[3], &b[4], &b[5], &b[6]);
        ans = 82;
        dfs(a, 0);
        if (ans == 82) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
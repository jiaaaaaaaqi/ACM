#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx = 1005;
const double eps = 1e-8;
double a[mx][mx], x[mx];
int mp[mx][mx];
int n, k;

bool check(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !mp[x][y];
}

int id(int x, int y) {
    return x * n + y;
}

int Gauss(int equ, int var) {
    for (int i = 0; i <= var; i++) x[i] = 0;
    int max_r, row, col;
    for (row = 0, col = 0; row < equ && col < var; col++) {
        max_r = row;
        for (int i = row+1; i < equ; i++) {
            if (fabs(a[i][col]) > fabs(a[max_r][col])) max_r = i;
        }
        if (max_r != row)swap(a[max_r], a[row]);
        if (fabs(a[row][col]) < eps) continue;
        for (int i = row+1; i < equ; i++){
            double temp = a[i][col] / a[row][col];
            for (int j = col; j <= var; j++) {
                a[i][j] -= a[row][j] * temp;
            }
        }
        row++;
    }
    for (int i = row; i < equ; i++) {
        if (fabs(a[i][col] > eps)) return -1;
    }
    if (row < equ) return -1;
    
    for (int i = var-1; i >= 0; i--) {
        double temp = a[i][var];
        for (int j = i+1; j < var; j++) {
            temp -= a[i][j]*x[j];
        }
        x[i] = temp / a[i][i];
    } 
    return 0;
}

// int Gauss(int equ, int var){

//     int i,j,k,col,max_r;

//     for(k=0,col=0;k<equ&&col<var;k++,col++){
//         max_r=k;

//         for(i=k+1;i<equ;i++)
//             if(fabs(a[i][col])>fabs(a[max_r][col]))
//                 max_r=i;

//         if(fabs(a[max_r][col])<eps)return 0;

//         if(k!=max_r){
//             for(j=col;j<var;j++)
//             swap(a[k][j],a[max_r][j]);
//             swap(x[k],x[max_r]);
//         }

//         x[k]/=a[k][col];
//         for(j=col+1;j<var;j++)a[k][j]/=a[k][col];
//         a[k][col]=1;
//     }
//     for(i=0;i<equ;i++)
//         if(i!=k){
//             x[i] -= x[k]*a[i][col];
//             for(j=col+1;j<var;j++)a[i][j] -= a[k][j]*a[i][col];
//             a[i][col]=0;
//         }
//     return 1;
// }
int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        memset(mp, 0, sizeof(mp));
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &k);
        while (k--) {
            int x, y;
            scanf("%d%d", &x, &y);
            mp[x][y] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ha = id(i,j);
                int d = 1;
                if (check(i, j+1)) d++;
                if (check(i, j-1)) d++;
                if (check(i+1, j)) d++;
                if (check(i-1, j)) d++;

                if (check(i, j+1)) a[id(i,j+1)][id(i,j)] += 1.0 / d;
                if (check(i, j-1)) a[id(i,j-1)][id(i,j)] += 1.0 / d;
                if (check(i+1, j)) a[id(i+1,j)][id(i,j)] += 1.0 / d;
                if (check(i-1, j)) a[id(i-1,j)][id(i,j)] += 1.0 / d;
                a[id(i,j)][id(i,j)] += 1.0 / d;
                a[id(i,j)][id(i,j)] -= 1;
            }
        }
        //a[id(0,0)][n*n] = -1;
        for (int i = 0; i < n*n; i++) a[n*n][i] = 1;
        a[n*n][n*n] = 1;

        for (int i = 0; i < n*n+1; i++) {
            for (int j = 0; j < n*n+1; j++) {
                printf("%.5f%c", a[i][j], j==n*n?'\n':' ');
            }
        }
        int op = Gauss(n*n+1, n*n);
        printf("%d\n", op);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%.5f%c", x[id(i,j)], j==n-1?'\n':' ');
            }
        }
    }
    return 0;
}

        // a[0][0] = 1;
        // a[0][1] = 1;
        // a[0][2] = 3;
        // a[1][0] = 1;
        // a[1][1] = -1;
        // a[1][2] = 1;

        // cout << Gauss(2, 2) << endl;
        // for (int i = 0; i < 2; i++) printf("%f\n", x[i]);

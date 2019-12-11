#include <bits/stdc++.h>

using namespace std;
const int mx = 100005;
int a[mx];
bool vis1[mx], vis2[mx], vis3[mx], vis4[mx];

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            vis1[i] = vis2[i] = vis3[i] = vis4[i] = false;
        }   
        vis1[1] = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] >= a[i-1]) vis1[i] = true;
            else break;
        }
        vis2[n] = true;
        for (int i = n-1; i >= 1; i--) {
            if (a[i] <= a[i+1]) vis2[i] = true;
            else break;
        }

        vis3[1] = true;
        for (int i = 2; i <= n; i++) {
            if (a[i] <= a[i-1]) vis3[i] = true;
            else break;
        }
        vis4[n] = true;
        for (int i = n-1; i >= 1; i--) {
            if (a[i] >= a[i+1]) vis4[i] = true;
            else break;
        }

        if (n <= 2) puts("YES");
        else {
            if (vis1[n-1] || vis2[2] || vis3[n-1] || vis4[2]) puts("YES");
            else {
                bool flag = false;
                for (int i = 2; i <= n-1; i++) {
                    if (vis1[i-1] && vis2[i+1] && a[i+1] >= a[i-1]) flag = true;
                    if (vis3[i-1] && vis4[i+1] && a[i+1] <= a[i-1]) flag = true;
                    if (flag) break;
                }
                puts(flag?"YES":"NO");
            }
        }
    }
    return 0;
}
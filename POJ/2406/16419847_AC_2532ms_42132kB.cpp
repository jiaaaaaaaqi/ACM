/*
复杂度接近O(n)
所有相关数组都要开三倍
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int maxn = 1000010;
int wa[maxn * 3], wb[maxn * 3], wv[maxn * 3], wss[maxn * 3];
int c0(int *r, int a, int b) {
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b) {
    if (k == 2)
        return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
    else return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
}
void sort(int *r, int *a, int *b, int n, int m) {
    int i;
    for (i = 0; i < n; i++) wv[i] = r[a[i]];
    for (i = 0; i < m; i++) wss[i] = 0;
    for (i = 0; i < n; i++) wss[wv[i]]++;
    for (i = 1; i < m; i++)wss[i] += wss[i - 1];
    for (int i = n - 1; i >= 0; i--)
        b[--wss[wv[i]]] = a[i];
}
void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)    dc3(rn, san, tbc, p);
    else for (i = 0; i < tbc; i++)  san[rn[i]] = i;
    for (i = 0; i < tbc; i++)   if (san[i] < tb)    wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++)   wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++) sa[p] = wa[i++];
    for (; j < tbc; p++)sa[p] = wb[j++];
}
//str和sa也要开三倍
void da(int str[], int sa[], int rk[], int height[], int n, int m) {
    for (int i = n; i < 3 * n; i++)
        str[i] = 0;
    dc3(str, sa, n + 1, m);
    int i, j, k = 0;
    for (int i = 0; i <= n; i++) rk[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (str[i + k] == str[j + k])k++;
        height[rk[i]] = k;
    }
}

int m, n, k, t;
int rk[maxn * 3], height[maxn * 3], str[maxn * 3], sa[maxn * 3];

char s[maxn];
int main() {
    while (~scanf("%s", s)) {
        if (s[0] == '.')break;
        n = strlen(s);
        for (int i = 0; i < n; i++)
            str[i] = s[i];
        str[n] = 0;
        da(str, sa, rk, height, n, 300);
        int aa = n - height[rk[0]];
        int ans = 1;
        if (n % aa == 0) {
            ans = n / aa;
        }
        printf("%d\n", ans);
    }
    return 0;
}

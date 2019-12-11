#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

long long int e_gcd(long long int a, long long int b, long long int &x, long long int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        long long int d = e_gcd(b, a % b, x, y);
        long long int temp = y;
        y = x - a / b * y;
        x = temp;
        return d;
    }
}

int main() {
    long long int A, B, C, k;
    while (scanf("%lld%lld%lld%lld", &A, &B, &C, &k), A || B || C || k) {
        long long int a = C;
        long long int c = B - A;
        long long int b = (long long int) 1 << k;
        long long int x, y;
        long long int d = e_gcd(a, b, x, y);
        if (c % d)
            printf("FOREVER\n");
        else {
            long long int r = b / d;
//            long long int ans = ((c / d * x) % r + r) % r;
            long long int x1;
            long long int b1 = b / d;
            x1 = (x + b1) * (c / d);
            x1 = (x1 % b1 + b1) % b1;
            printf("%lld\n", x1);
        }
    }
    return 0;
}
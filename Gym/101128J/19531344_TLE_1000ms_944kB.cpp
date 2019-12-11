#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const unsigned int maxl=10000+10, maxs=50000+10;
struct dot{
    long long x, y;
    bool operator< (dot &t) const
    {
        return (x*t.y - t.x*y) > 0;
    }
    bool operator<= (dot &t) const
    {
        return (x*t.y - t.x*y) >= 0;
    }
    dot operator+ (dot &t) const
    {
        return dot{x+t.x, y+t.y};
    }
    dot operator- (dot &t) const
    {
        return dot{x-t.x, y-t.y};
    }
}l[maxl], s[maxs];

dot inv(dot t)
{
    return dot{-t.x,-t.y};
}
int main()
{
    int L, S;
    int x, y;
    dot a, b;
    int ans = 0;
    scanf("%d", &L);
    for (int i = 0; i < L; i++){
        scanf("%d%d", &x, &y);
        l[i].x = x; l[i].y = y;
    }
    scanf("%d", &S);
    for (int i = 0; i < S; i++){
        scanf("%d%d", &x, &y);
        //s[i].x = x; s[i].y = y;

        a.x = l[0].x - x;
        a.y = l[0].y - y;

        b.x = l[1].x - x;
        b.y = l[1].y - y;
        if (b < a)
        {
            dot t;
            t = a; a = b; b = t;
        }
        for(int j = 2; j < L; j++)
        {
            dot c = inv(a);
            dot t;
            t.x = l[j].x - x;
            t.y = l[j].y - y;

            if (inv(b)<t && t<a)
                a = t;
            else if (b<t && t<c)
                b = t;
            else if (!(a<=t && t<=b))
            {
                ans++;
                break;
            }
        }

    }
    cout << ans << endl;
    return 0;
}

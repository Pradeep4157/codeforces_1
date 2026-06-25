#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    at odd k changing x is a, and changing y is b.

    at even k changing x is b, and changing y is a..

    so whatever's minimum i will do that min(2 * abs(x),2 * abs(y)) times

    because i am making a move alt..



    now how much distance have i covered till now :




*/
int solve(int x, int y, int a, int b)
{
    int res = 0;
    if (a <= b)
    {
        // spamming a as many times..
        int min_ops = min(2 * x, 2 * y);
        res += min_ops * a;
        // now we are rem with ..
        // since x is the first thing..
        x -= (min_ops / 2);
        y -= (min_ops / 2);
        // now whatever's rem..
        if (x > 0)
        {
            // then i keep taking  a,b whatever..
            // what if 4 * a <= (b) then i will keep using a..
            if ((4 * a) <= b)
            {
                // how many times ?
                int dist = x;
                if (dist == 1)
                {
                    res += a;
                }
                else
                {
                    // i move a on 1,3,5,7,9,11,...
                    // and on 2,4,6,.... i do y + 1, y - 1..
                    int req = x * 2;
                    res += (req * a);
                    if (x & 1)
                    {
                        // i need to put y back to its place..
                        y += b;
                    }
                }
            }
            else
            {
                // it is better to take a,b,a,b
                // i take alt steps where
                int first = (x + 1) / 2;
                int second = x / 2;
                res += (first * a);
                res += (second * b);
            }
        }
        if (y > 0)
        {
            if (y == 1)
            {
                // i might just take b or 3 * a
                res += min(3 * a, b);
            }
            else
            {
                if ((4 * a) <= b)
                {
                    int req = y * 2;
                    res += (req * a);
                    if (y & 1)
                        res += b;
                }
                else
                {
                    int first = (y + 1) / 2;
                    int second = y / 2;
                    res += (first * b);
                    res += (second * a);
                }
            }
        }
    }
    else
    {
        res = 1e12;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        x = abs(x);
        y = abs(y);
        int res = solve(x, y, a, b);
        res = min(res, solve(x, y, b, a));
        cout << res << endl;
    }
    return 0;
}

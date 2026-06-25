#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, x;
        cin >> a >> b >> x;
        int res = abs(a - b);
        int ops = 0;
        while (true)
        {
            if (a == 0 && b == 0)
                break;
            if (a > b)
                swap(a, b);
            res = min(res, ops + abs(b - a));
            ops++;
            b /= x;
            res = min(res, ops + abs(b - a));
        }
        cout << res << endl;
    }
    return 0;
}

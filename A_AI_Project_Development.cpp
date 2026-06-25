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
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        int res = (n + x + y - 1) / (x + y);
        int res_1 = 0;
        if (z >= ((n + x - 1) / x))
        {
            res_1 = (n + x - 1) / x;
        }
        else
        {
            // first z hours we complete z * x lines of code..
            res_1 = z;
            n -= z * x;
            n = max(n, 0ll);
            y *= 10;
            res_1 += (n + x + y - 1) / (x + y);
        }
        res = min(res, res_1);
        cout << res << endl;
    }
    return 0;
}

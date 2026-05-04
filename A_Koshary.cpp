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
        int x, y;
        cin >> x >> y;
        int odd = 0;
        if (x & 1)
            odd++;
        if (y & 1)
            odd++;
        if (odd > 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

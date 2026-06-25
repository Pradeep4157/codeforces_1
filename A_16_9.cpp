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
    int t = 1;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        bool ok = false;
        if ((x * 9) == (y * 16))
        {
            ok = 1;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

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
    int m, d;
    cin >> m >> d;
    map<int, int> mp;
    mp[1] = 7;
    mp[3] = 3;
    mp[5] = 5;
    mp[7] = 7;
    mp[9] = 9;
    bool ok = false;
    if (mp[m] == d)
    {
        ok = 1;
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}

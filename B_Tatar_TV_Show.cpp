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
        map<int, int> mp;
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            if (s[i] == '1')
                curr++;
            if (curr >= 1)
                mp[i % k]++;
        }
        bool ok = 1;
        for (auto a : mp)
        {
            if (a.second & 1)
                ok = false;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

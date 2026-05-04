#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
const int mod = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> prefix(n, -1), suffix(n, n);
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
        {
            if (s[i] == s[i + 1])
                prefix[i] = i;
        }
        if (i)
            prefix[i] = max(prefix[i], prefix[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1)
        {
            if (s[i] == s[i + 1])
                suffix[i] = i;
        }
        if (i < n - 1)
            suffix[i] = min(suffix[i], suffix[i + 1]);
    }
    // for (auto a : suffix)
    //     cout << a << ' ';
    // cout << endl;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // this is our inclusion..
        int end = suffix[i];
        end = min(end, n - 1);
        res += (end - i + 1);
        res %= mod;
    }
    cout << res << endl;
    return 0;
}

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
    vector<int> dp(n + 10);
    vector<pair<int, int>> next(n + 10);
    vector<int> same(n + 10);
    int last_a = n, last_b = n, last_c = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'a')
        {
            next[i].first = last_b;
            next[i].second = last_c;
            same[i] = last_a;
            last_a = i;
        }
        else if (s[i] == 'b')
        {

            next[i].first = last_a;
            next[i].second = last_c;
            same[i] = last_b;
            last_b = i;
        }
        else
        {
            next[i].first = last_a;
            next[i].second = last_b;
            same[i] = last_c;
            last_c = i;
        }
    }
    vector<int> same_dp(n + 10);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = 1;
        if (same[i] < n)
            same_dp[i] += dp[same[i]];
        same_dp[i] += same_dp[same[i]];
        if (next[i].first != n)
        {
            curr += dp[next[i].first];
            curr %= mod;
            curr += same_dp[next[i].first];
            curr %= mod;
        }
        if (next[i].second != n)
        {
            curr += dp[next[i].second];
            curr %= mod;
            curr += same_dp[next[i].second];
            curr %= mod;
        }

        curr %= mod;
        dp[i] = curr;
    }

    int res = 0;
    for (auto a : dp)
    {

        res += a;
        res %= mod;
    }

    res %= mod;
    cout << res << endl;
    return 0;
}

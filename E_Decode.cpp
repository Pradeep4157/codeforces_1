#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    the structure is that we find x,y

    using + 1 if its 0 and -1 if its 1..

    so we will have all the same end points that is that segment ..

    now for each segment we can have l + 2 * (n - r)..

    that should do it..

    the structure is right but we are getting TLE because  of the n^2  loop..

    we can use suffixes for the optimization..

    so x*a + x*b = x*(a + b) we can use this..


*/
const int mod = (int)(1e9 + 7);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        map<int, vector<int>> mp;
        mp[0].push_back(-1);
        int curr = 0;
        for (int i = 0; i < n; i++)
        {
            curr += ((s[i] == '0') ? 1 : -1);
            mp[curr].push_back(i);
        }
        int res = 0;
        for (auto a : mp)
        {
            int size = a.second.size();
            if (size < 2)
                continue;
            vector<int> &curr = a.second;
            int right = 0;
            for (int l = size - 1; l >= 0; l--)
            {
                int left = curr[l] + 2;
                res += (left * right);
                res %= mod;
                right += (n - curr[l]);

                // for (int r = l + 1; r < size; r++)
                // {
                //     int left = curr[l] + 2;
                //     int right = n - curr[r];
                //     res += (left * right);
                //     res %= mod;
                // }
            }
        }
        cout << res << endl;
    }
    return 0;
}

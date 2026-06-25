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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        map<int, int> mp;

        for (auto a : arr)
        {
            mp[a]++;
        }

        int res = n / 2;
        int left = 0;
        for (auto a : mp)
        {
            int rem = n - a.second;
            int right = rem - left;

            res = min(res, max(left, right));
            left += a.second;
        }
        cout << res << endl;
    }
    return 0;
}

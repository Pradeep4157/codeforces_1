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
            cin >> arr[i];
        int res = 0;
        for (auto a : arr)
        {
            if (a == 0)
            {
                res++;
            }
        }
        map<int, int> mp;
        for (auto a : arr)
        {
            mp[a]++;
        }
        {
            int first = mp[1];
            int second = mp[2];
            int mini = min(first, second);
            res += mini;
            mp[1] -= mini;
            mp[2] -= mini;
        }
        {
            int first = mp[2];
            first /= 3;
            res += first;
        }
        {
            int first = mp[1];
            first /= 3;
            res += first;
        }
        cout << res << endl;
    }
    return 0;
}

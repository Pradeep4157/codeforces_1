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
        int n, x;
        cin >> n >> x;
        n++;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++)
        {
            if (res.empty())
            {
                res.push_back({i, arr[i]});
            }
            else
            {
                int prev = res[res.size() - 1].second;
                if (abs(arr[i] - prev) >= x)
                {
                    res.push_back({i, arr[i]});
                }
            }
        }
        for (auto a : res)
        {
            cout << a.first << " " << a.second << endl;
        }
    }
    return 0;
}

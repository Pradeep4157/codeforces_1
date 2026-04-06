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
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        vector<int> res(m + 1);
        for (int i = 0; i < n; i++)
        {
            res[arr[i].second]++;
            res[arr[i].first]--;
        }
        for (int i = 1; i <= m; i++)
        {
            cout << res[i] << endl;
        }
    }
    return 0;
}

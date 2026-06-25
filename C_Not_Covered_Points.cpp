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
        int n;
        cin >> n;
        int min_x = INT_MAX, min_y = INT_MAX;
        set<pair<int, int>> st;
        map<int, set<int>> mp, mp_1;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            min_x = min(min_x, x);
            min_y = min(min_y, y);
            mp[x].insert(y);
            arr.push_back({x, y});
            mp_1[y].insert(x);
        }
        int res = 0;
        sort(arr.begin(), arr.end());
        {
            int min_y = INT_MAX, min_x = INT_MAX;
            int i = 0;
            while (i < n)
            {
                int j = i;
                while (j < n && (arr[i].first == arr[j].first))
                    j++;
                for (int k = i; k < j; k++)
                {
                    if (min_y >= arr[k].second)
                        res++;
                }
                for (int k = i; k < j; k++)
                {
                    min_y = min(min_y, arr[k].second);
                }
                i = j;
            }
        }
        cout << res << endl;
    }
    return 0;
}

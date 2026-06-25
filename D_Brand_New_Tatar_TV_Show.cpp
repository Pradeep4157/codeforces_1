#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    every new op y >= x

    and y - x <= k..

    lets say we start from a group..

    there are some upper groups that

    we can take..

    maybe not if the diff is too big.

    so we start from biggest group..

    if there is only 1 group :

        then if freq is even then egor wins

        else he looses..

    also its not needed that they are going

    to take all the elements from this group

    they might skip to win..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> mp;
        for (auto a : arr)
        {
            mp[a]++;
        }
        bool wins = false;
        if (mp.size() == 1)
        {
            if (mp[arr[0]] & 1)
            {
                wins = false;
            }
            else
                wins = true;
        }
        else
        {

            // here he will try to reach some end group that is even or 1 group before..
            vector<pair<int, int>> temp;
            for (auto a : mp)
            {
                temp.push_back({a.first, a.second});
            }
            int m = temp.size();
            for (int i = m - 1; i >= 0; i--)
            {
                if ((temp[i].second % 2) == 0)
                {
                    wins = 1;
                    break;
                }
                else
                {
                    if ((i > 0) && ((temp[i].first - temp[i - 1].first) <= k))
                    {
                        wins = 1;
                        break;
                    }
                }
            }
        }
        cout << ((wins) ? "YES" : "NO") << endl;
    }
    return 0;
}

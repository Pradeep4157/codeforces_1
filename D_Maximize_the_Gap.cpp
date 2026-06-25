#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    15


*/
int n, k;
bool possible(int mid, vector<pair<int, int>> &arr)
{
    vector<int> dp;
    dp.push_back(arr[0].second);
    for (int i = 0; i < n; i++)
    {
        if (dp.size() >= k)
            return true;
        int curr_y = arr[i].second;
        int curr_x = arr[i].first;
        bool ok = 1;
        while (!dp.empty())
        {
            int last = dp.back();
            if (last <= (curr_x - mid))
            {
                break; // we can pair these 2...
            }
            // either we keep back of dp or we keep this thing..
            if (last > curr_y)
            {
                dp.pop_back();
            }
            else
            {
                ok = false; // we should not pop that back as its better..
                break;
            }
        }
        if (ok)
        {
            dp.push_back(curr_y);
        }
    }
    return (dp.size() >= k);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b)
             {
            if(a.first != b.first){
                return a.first < b.first;
            }
            else{
                return a.second > b.second;
            } });
        int low = 1, high = 1e9;
        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid, arr))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }

        cout << res << endl;
    }
    return 0;
}

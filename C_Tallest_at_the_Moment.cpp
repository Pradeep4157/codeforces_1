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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        vector<int> suffix(n);
        sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b)
             {
            // on the basis of small time..
            if(a.second != b.second){
                return a.second < b.second;
            }
            else{
                return a.first < b.first;
            } });
        int max_height = 0;
        vector<int> times;
        for (int i = 0; i < n; i++)
        {
            times.push_back(arr[i].second - 1);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            max_height = max(max_height, arr[i].first);
            suffix[i] = max_height;
        }
        // for (auto a : suffix)
        //     cout << a << " ";
        // cout << endl;
        int q;
        cin >> q;
        while (q--)
        {
            int curr_time;
            cin >> curr_time;
            auto it = lower_bound(times.begin(), times.end(), curr_time);
            if (it == times.end())
                it--;
            int idx = it - times.begin();
            cout << suffix[idx] << endl;
        }
    }
    return 0;
}

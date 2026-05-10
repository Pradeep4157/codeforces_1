#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    1 1 1 4 4 5

    1 0 -1 -2

    1 + 3 + 3 + 3







*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        set<int> st;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int maxi = *max_element(arr.begin(), arr.end());
        int index = -1;
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == maxi)
            {
                index = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == index)
                continue;
            if (arr[i] >= 0)
                pos.push_back(arr[i]);
            else
                neg.push_back(arr[i]);
        }
        sort(pos.begin(), pos.end());
        vector<int> temp;
        map<int, int> mp;
        for (auto a : pos)
        {
            mp[a]++;
        }
        for (auto &a : mp)
        {
            temp.push_back(a.first);
            a.second--;
        }
        for (auto &a : mp)
        {
            while (a.second > 0)
            {
                a.second--;
                temp.push_back(a.first);
            }
        }
        sort(neg.begin(), neg.end());
        arr = temp;
        for (auto a : neg)
            arr.push_back(a);
        arr.insert(arr.begin() + 0, maxi);
        // for (auto a : arr)
        //     cout << a << " ";
        // cout << endl;
        int res = 0;
        int curr_mex = 0;
        for (int i = 0; i < n; i++)
        {
            // maxi is maxi..
            // remove this ele from st..

            res += maxi;
            st.insert(arr[i]);
            while (st.count(curr_mex))
            {
                curr_mex++;
            }
            res += curr_mex;
        }
        cout << res << endl;
    }
    return 0;
}

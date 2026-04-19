#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    cap lim is ai that is ai courses can only be assigned to this..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> m >> n;

        vector<int> arr(m), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }

        int target = n + 1;
        int req = 0;

        for (auto a : arr)
        {

            req += max(0ll, target - a);
        }
        if (req <= 1000)
        {
            cout << req << endl;
            vector<pair<int, int>> temp;
            for (int i = 0; i < m; i++)
            {
                temp.push_back({arr[i], i});
            }
            sort(temp.rbegin(), temp.rend());
            for (int i = 0; i < m; i++)
            {
                int a = temp[i].first;
                int curr_req = max(0LL, target - a);
                while (curr_req)
                {
                    cout << temp[i].second + 1 << " ";
                    curr_req--;
                }
            }
        }

        cout << endl;
    }
    return 0;
}

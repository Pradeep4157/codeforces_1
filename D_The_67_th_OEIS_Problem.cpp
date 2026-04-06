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
        int curr = 1;
        int req = 1;
        int next = req + 1;
        vector<int> arr;
        arr.push_back(1);

        int i = 0;
        while (true)
        {
            if (i == n - 1)
                break;
            i++;
            arr.push_back(next * req);

            next++;
            req++;
        }
        map<int, int> mp;
        for (int i = 0; i < n - 1; i++)
        {
            int curr_gcd = __gcd(arr[i], arr[i + 1]);
            mp[curr_gcd]++;
            if (curr_gcd == 6)
                cout << arr[i] << ":::" << arr[i + 1] << endl;
        }

        for (auto a : mp)
        {
            if (a.second > 1)
                cout << a.first << ":" << a.second << endl;
        }
    }
    return 0;
}

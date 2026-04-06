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
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int all_xorr = 0;
        for (auto a : arr)
        {
            all_xorr ^= a;
        }
        for (int left = 0; left < n; left++)
        {
            int curr_xorr = all_xorr ^ arr[left];
            for (int right = 0; right < n; right++)
            {
                if (left == right)
                    continue;
                curr_xorr ^= arr[right];
                int prev = arr[left] ^ curr_xorr;
                int ele = arr[right] ^ curr_xorr;
                ele ^= prev;
                res = max(res, ele);
            }
        }
        cout << res << endl;
    }

    return 0;
}

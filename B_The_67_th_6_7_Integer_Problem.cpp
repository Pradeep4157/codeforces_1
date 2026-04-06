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
        int n = 7;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = -arr[i];
        }
        int res = accumulate(arr.begin(), arr.end(), 0LL);
        cout << res << endl;
    }
    return 0;
}

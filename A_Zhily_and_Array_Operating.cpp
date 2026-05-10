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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i < n - 1)
            {
                int temp = arr[i] + arr[i + 1];
                arr[i] = max(arr[i], temp);
            }
            if (arr[i] > 0)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}

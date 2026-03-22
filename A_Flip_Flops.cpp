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
        int n, c, k;
        cin >> n >> c >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= c)
            {
                res++;
                // we get arr[i] we can take c..
                if (arr[i] < c)
                {
                    int can_inc = c - arr[i];
                    can_inc = min(can_inc, k);
                    arr[i] += can_inc;
                    k -= can_inc;
                }
                c += arr[i];
            }
        }
        cout << c << endl;
    }
    return 0;
}

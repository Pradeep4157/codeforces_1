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
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        int x, y;
        bool ok = 1;
        if (n >= 2)
        {
            x = arr[0];
            y = arr[1];
            for (int i = 0; i < n - 2; i++)
            {
                if (arr[i + 2] != (arr[i] % arr[i + 1]))
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok)
            cout << x << " " << y << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

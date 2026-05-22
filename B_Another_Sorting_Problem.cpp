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
        int min_req = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                min_req = max(min_req, arr[i - 1] - arr[i]);
            }
        }
        bool ok = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
            {
                // we add this..
                arr[i] += min_req;
            }
            if (arr[i] < arr[i - 1])
            {
                ok = false;
                break;
            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            int claim = arr[arr[i] - 1];
            int belongs = b[arr[i] - 1];
            if (belongs == i + 1)
                continue;
            // int curr_belongs = b[i]
            // if (arr[arr[i] - 1] == b[i])
            //     continue;
            else
            {
                // cout << i << endl;

                ok = false;
                break;
            }
        }
        cout << ((ok) ? "Yes" : "No") << endl;
    }
    return 0;
}

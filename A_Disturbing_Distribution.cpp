#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if 1 then combine with some big..
*/
const int mod = 676767677;
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
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                bool found = false;
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] >= arr[i])
                    {
                        found = 1;
                        break;
                    }
                }
                if (found == false)
                    res += arr[i];
            }
            else
                res += arr[i];
            res 
        }
        cout << res << endl;
    }
    return 0;
}

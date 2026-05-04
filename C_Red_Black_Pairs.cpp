#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    one way is that i either pair

    it horizontally or vertically..

    so at i i either pari i with i - 1

    and below i with i - 1

    or

    i with i and best cost till i - 1


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
        int lim = 2;
        vector<vector<char>> arr(2, vector<char>(n));
        for (int i = 0; i < lim; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<int> dp(n);
        dp[0] = ((arr[0][0] == arr[1][0]) ? 0 : 1);
        for (int i = 1; i < n; i++)
        {
            // either i with i..
            {
                int curr = 0;
                if (arr[0][i] != arr[1][i])
                {
                    curr++;
                }
                curr += dp[i - 1];
                dp[i] = curr;
            }
            // or with i - 1
            {
                int curr = 0;
                if (arr[0][i] != arr[0][i - 1])
                    curr++;
                if (arr[1][i] != arr[1][i - 1])
                    curr++;
                if (i >= 2)
                    curr += dp[i - 2];
                dp[i] = min(dp[i], curr);
            }
        }
        cout << dp[n - 1] << endl;
    }
    return 0;
}

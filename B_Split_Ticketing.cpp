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
    int n;
    cin >> n;
    vector<vector<int>> arr(n - 1);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++)
    {
        int curr = n - i - 1;
        for (int j = 0; j < curr; j++)
        {
            int ele;
            cin >> ele;
            dp[i][i + j + 1] = ele;
        }
    }
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int first = dp[i][j] + dp[j][k];
                int second = dp[i][k];

                if (first < second)
                    found = 1;
            }
        }
    }
    cout << ((found) ? "Yes" : "No") << endl;
    return 0;
}

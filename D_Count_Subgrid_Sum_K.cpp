#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    maybe we brute force

    on left top index.. {i,j}

    and then we select some k from i...n - 1

    and then we binary search / lower bound to find

    l where from i..i + k,j...l the sum of the grid

    is == k..

    we can maintain prefix..


    prefix[i][j] will contain all the sum from 0...ith row

    and j...m - 1 col..


    at any place dp / prefix[i][j] = prefix[i - 1][j] + prefix[i][j + 1]..

    and then when i finding mid..

    prefix[k][mid] - prefix[i - 1][mid]




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            string curr;
            cin >> curr;
            for (int j = 0; j < m; j++)
            {
                if (curr[j] == '0')
                    arr[i][j] = 0;
                else
                    arr[i][j] = 1;
            }
        }
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[i][j] = arr[i][j];

                if (i > 0)
                    dp[i][j] += dp[i - 1][j];

                if (j + 1 < m)
                    dp[i][j] += dp[i][j + 1];

                if (i > 0 && j + 1 < m)
                    dp[i][j] -= dp[i - 1][j + 1];
            }
        }
        // for (auto a : dp)
        // {
        //     for (auto b : a)
        //         cout << b << " ";
        //     cout << endl;
        // }
        vector<vector<int>> row_prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                row_prefix[i][j] = arr[i][j];
                if (j + 1 < m)
                {
                    row_prefix[i][j] += row_prefix[i][j + 1];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // this is the top left cell..
                int curr_sum = 0;
                for (int K = i; K < n; K++)
                {
                    curr_sum += row_prefix[K][j];
                    // this is the botton row..
                    int low = j, high = m - 1;
                    int left = -1, right = -1;
                    while (low <= high)
                    {
                        int mid = (low + high) / 2;
                        // mid is going to be the right most cell..
                        int temp = curr_sum;
                        // now we remove mid + 1...m - 1 from i..i + k..
                        if (mid + 1 < m)
                        {
                            temp -= dp[K][mid + 1];
                        }
                        // now we add back that extra sub..
                        if ((i - 1 >= 0) && (mid + 1 < m))
                        {
                            temp += dp[i - 1][mid + 1];
                        }
                        if (temp == k)
                        {
                            left = mid;

                            high = mid - 1;
                        }
                        else if (temp < k)
                        {
                            low = mid + 1;
                        }
                        else
                            high = mid - 1;
                    }
                    low = j, high = m - 1;
                    while (low <= high)
                    {
                        int mid = (low + high) / 2;
                        // mid is going to be the right most cell..
                        int temp = curr_sum;
                        // now we remove mid + 1...m - 1 from i..i + k..
                        if (mid + 1 < m)
                        {
                            temp -= dp[K][mid + 1];
                        }
                        // now we add back that extra sub..
                        if ((i - 1 >= 0) && (mid + 1 < m))
                        {
                            temp += dp[i - 1][mid + 1];
                        }
                        if (temp == k)
                        {
                            right = mid;
                            low = mid + 1;
                        }
                        else if (temp < k)
                        {
                            low = mid + 1;
                        }
                        else
                            high = mid - 1;
                    }

                    int ans = 0;
                    if (left != -1)
                        ans = right - left + 1;
                    res += ans;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}

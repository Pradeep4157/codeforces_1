#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    for every element i, i have 2 options..

    either i make it pos or neg..

    if i make it pos then  if this is mergable with i - 1

    dp[i].first = dp[i - 1].first + 1;

    else it is 1 because prev is bigger than this ?

    and at the end res is sum of dp ..

    no res is not that..

    i will have to store res as well..

    so that i know which state have i merged



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, pair<int, int>>> dp(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i].first = {1, 1};
            dp[i].second = {1, 1};
            res = 1;
            continue;
        }
        {
            // if i choose to let it be pos only..
            // first i will find prev..
            int curr_ele = arr[i];
            int prev_1 = 1, prev_2 = 1;
            if (i - 1 >= 0 && arr[i - 1] <= curr_ele)
            {
                // yay we can merge with pos of i - 1..
                // first i will take its dp..
                prev_1 += dp[i - 1].first.second;
                // i will also take all the subarrays
                prev_1 += dp[i - 1].first.first + 1;
                dp[i].first.first = dp[i - 1].first.first + 1;
                dp[i].first.second = prev_1;
            }
            else
            {
                // meow meow meow meow..
                // so we will only have 1 here and we will
                // take best of prev..
                dp[i].first.first = 1;
                dp[i].first.second = 1;
                if (i - 1 >= 0)
                {
                    int best = max(dp[i - 1].first.second, dp[i - 1].second.second);
                    dp[i].first.second += best;
                }
            }
            // now can i merge it with -arr[i - 1]
            if (i - 1 >= 0 && (-arr[i - 1] <= curr_ele))
            {
                prev_2 += dp[i - 1].second.second;
                prev_2 += dp[i - 1].second.first + 1;
                dp[i].first.first = max(dp[i].first.first, dp[i - 1].second.first + 1);
            }
            dp[i].first.second = max({dp[i].first.second, prev_1, prev_2});
        }

        {
            // if i choose to let it be pos only..
            // first i will find prev..
            int curr_ele = -arr[i];
            int prev_1 = 0, prev_2 = 0;
            if (i - 1 >= 0 && arr[i - 1] <= curr_ele)
            {
                // yay we can merge with pos of i - 1..
                // first i will take its dp..
                prev_1 += dp[i - 1].first.second;
                // i will also take all the subarrays
                prev_1 += dp[i - 1].first.first + 1;
                dp[i].second.first = dp[i - 1].first.first + 1;
                dp[i].second.second = prev_1;
            }
            else
            {
                // meow meow meow meow..
                // so we will only have 1 here and we will
                // take best of prev..
                dp[i].second.first = 1;
                dp[i].second.second = 1;
                if (i - 1 >= 0)
                {
                    int best = max(dp[i - 1].first.second, dp[i - 1].second.second);
                    dp[i].second.second += best;
                }
            }
            // now can i merge it with -arr[i - 1]
            if (i - 1 >= 0 && (-arr[i - 1] <= curr_ele))
            {
                prev_2 += dp[i - 1].second.second;
                prev_2 += dp[i - 1].second.first + 1;
                dp[i].second.first = max(dp[i].second.first, dp[i - 1].second.first + 1);
            }
            else{
                prev_2 = 
            }
            dp[i].second.second = max({dp[i].second.second, prev_1, prev_2});
        }
        res = max({res, dp[i].first.second, dp[i].second.second});
    }
    cout << res << endl;

    return 0;
}

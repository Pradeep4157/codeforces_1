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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n, 0);
        vector<bool> left_greater(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                left_greater[i] = 1;
            }
            st.push(i);
        }

        for (int i = 1; i < n; i++)
        {
            if (left_greater[i] == false)
                continue;
            if (arr[i] < arr[i - 1])
            {
                dp[i] = 1;
            }
            else if (arr[i] > arr[i - 1])
            {
                dp[i] += dp[i - 1] + 1;
            }
        }
        for (auto a : dp)
        {
            cout << a << ' ';
        }
        cout << endl;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}

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
        int n, m;
        cin >> n >> m;
        vector<set<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int first, second;
            cin >> first >> second;
            first--;
            second--;
            adj[first].insert(second);
            adj[second].insert(first);
        }
        for (int i = 0; i < n; i++)
        {
            adj[i].insert(i);
        }
        int w;
        cin >> w;
        vector<string> holidays(n);
        for (int i = 0; i < n; i++)
        {

            cin >> holidays[i];
        }
        vector<vector<set<int>>> dp(n, vector<set<int>>(w));
        for (int i = 0; i < n; i++)
        {
            if (holidays[i][w - 1] == 'o')
            {

                dp[i][w - 1].insert(i);
            }
        }
        for (int day = w - 2; day >= 0; day--)
        {
            for (int i = 0; i < n; i++)
            {
                if (holidays[i][day] == 'o')
                {

                    // we can stay here.. but also there should be way to  reach end..
                    for (auto &nei : adj[i])
                    {

                        if (dp[nei][day + 1].empty())
                            continue;
                        for (auto &ends : dp[nei][day + 1])
                        {
                            dp[i][day].insert(ends);
                        }
                    }
                }
            }
        }
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (dp[i][0].empty())
                continue;
            cout << holidays[i][0] << "___" << endl;
            cout << i << "->";
            for (auto a : dp[i][0])
                cout << a << " ";
            cout << endl;
            // we have reached here from some end..
            for (auto &end : dp[i][0])
            {

                if (adj[end].count(i))
                {
                    cout << i << ":" << end << endl;
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        cout << (found ? "Yes" : "No") << endl;
    }
    return 0;
}

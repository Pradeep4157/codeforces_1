#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so the structure is that i walk till some node then jump, then walk, again jump....






*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, m, y;
        cin >> n >> m >> y;
        vector<vector<int>> temp;
        for (int i = 0; i < m; i++)
        {
            int first, second, weight;

            cin >> first >> second >> weight;
            first--;
            second--;
            temp.push_back({first, second, weight});
        }
        vector<int> X(n);
        for (int i = 0; i < n; i++)
        {
            cin >> X[i];
        }

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto a : temp)
        {
            int first = a[0];
            int second = a[1];
            int weight = a[2];
            weight = min(weight, X[first] + X[second] + y);
            adj[first].push_back({second, weight});
            adj[second].push_back({first, weight});
        }
        // now we will add all the edges to the last node..
        for (int i = 0; i < n; i++)
        {
            // incoming..
            adj[i].push_back({n, X[i]});
            // outgoing..
            adj[n].push_back({i, X[i] + y});
        }

        vector<int> dp(n + 1, LLONG_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            vector<int> top = pq.top();
            pq.pop();
            int curr_dist = top[0];

            int node = top[1];
            if (dp[node] < curr_dist)
            {
                continue;
            }
            dp[node] = curr_dist;
            // i will visit all the nei and try to red their dp..
            for (auto &a : adj[node])
            {
                int nei = a.first;
                int weight = a.second;
                if (curr_dist + weight < dp[nei])
                {
                    dp[nei] = curr_dist + weight;
                    pq.push({weight + curr_dist, nei});
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

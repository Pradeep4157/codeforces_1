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
        int n, k, m;
        cin >> n >> k >> m;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int ci, vi;
            cin >> ci >> vi;
            mp[ci].push_back(vi);
        }
        for (auto &a : mp)
        {
            sort(a.second.begin(), a.second.end());
        }

        int res = 0;
        priority_queue<pair<int, int>> pq;
        for (auto a : mp)
        {
            pq.push({a.second.back(), a.first});
        }
        while (m--)
        {
            k--;
            pair<int, int> top = pq.top();
            pq.pop();
            int idx = top.second;
            int val = top.first;
            mp[idx].pop_back();
            res += val;
        }
        priority_queue<int> PQ;
        for (auto a : mp)
        {
            for (auto b : a.second)
                PQ.push(b);
        }
        while (k--)
        {
            int top = PQ.top();
            PQ.pop();
            res += top;
        }
        cout << res << endl;
    }
    return 0;
}

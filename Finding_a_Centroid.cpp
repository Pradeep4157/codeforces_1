#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we first find the diameter and then once we have that we will traverse

    radius steps from the end points that we have found while finding the

    diameter..

    so what are these end points we pick a random node like 1.

    find the farthest node from 1.

    and then from that node we find the farthese node..

    these nodes are sort of on the circum of the circle...




*/
vector<vector<int>> adj;
int n;
int D;
vector<int> dist;
void dfs(int node, int par, int curr_dist)
{
    dist[node] = curr_dist;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, curr_dist + 1);
        }
    }
}
int dfs2(int node, int par, int left)
{

        if (left == 0)
    {
        return node;
    }
    for (auto nei : adj[node])
    {
        if (nei != par && dist[nei] == dist[node] - 1)
        {
            int res = dfs2(nei, node, left - 1);
            return res;
        }
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    adj.clear();
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    dist.assign(n + 1, 0);
    dfs(1, -1, 0);
    int first = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= dist[first])
        {
            first = i;
        }
    }

    dist.assign(n + 1, 0);
    dfs(first, -1, 0);
    int second = first;
    int diameter = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= dist[second])
        {
            second = i;
            diameter = dist[i];
        }
    }

    D = (diameter) / 2;

    int res = dfs2(second, -1, diameter / 2);

    cout << res << endl;
    return 0;
}

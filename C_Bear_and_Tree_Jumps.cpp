#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can do this via basic dfs way where we store all the dist that  childs have seen and then


*/
vector<vector<int>> base_dp;
vector<int> cross_dp;
vector<vector<int>> adj;
vector<int> subtree;

void dfs_size(int node, int par)
{
    subtree[node] = 1;

    for (auto child : adj[node])
    {
        if (child == par)
            continue;

        dfs_size(child, node);
        subtree[node] += subtree[child];
    }
}

int find_centroid(int node, int par, int total_size)
{
    for (auto child : adj[node])
    {
        if (child == par)
            continue;

        if (subtree[child] > total_size / 2)
        {
            return find_centroid(child, node, total_size);
        }
    }

    return node;
}
void dfs(int node, int par)
{
    // first building the base dp...
    // first finding the base dp of all the childs..
    int max_child_size = 0;
    for (auto child : adj[node])
    {
        if (child != par)
        {

            dfs(child, node);
            // now child's base dp is built but not cross dp because the par which is this node is going to build that..
            // lets store all the base value of child in this node..

            int size = base_dp[child].size();
            max_child_size = max(max_child_size, size);
        }
    }
    base_dp[node].assign(max_child_size + 1, 0);
    base_dp[node][0] = 1;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            for (int i = 0; i < base_dp[child].size(); i++)
            {
                base_dp[node][i + 1] += base_dp[child][i];
            }
        }
    }
    // now base dp is done now we will imp cross dp.
    // we will do this only if there are >= 2 childs..
    if (adj[node].size() >= 2)
    {
        // because of the nei is par and rem are child..
        bool first = true;
        vector<int> temp;
        for (auto child : adj[node])
        {
            if (child != par)
            {
                if (first == true)
                {
                    // this is going to be used by others..
                    temp = base_dp[child];
                    first = false;
                }
                else
                {
                    // now this child will combine with all the prev childs..

                    for (int i = 0; i < temp.size(); i++)
                    {
                        // this value is going to be used by all the level nodes in this subgraph..
                        for (int j = 0; j < base_dp[child].size(); j++)
                        {
                            int index = i + j + 2;
                            // now this index is there..
                            cross_dp[index] += (base_dp[child][j] * temp[i]);
                        }
                    }
                    // now we add this childs base values so that other
                    for (int i = 0; i < base_dp[child].size(); i++)
                    {
                        // add all the childs / nodes in this subtree.
                        if (i >= temp.size())
                        {
                            temp.push_back(base_dp[child][i]);
                        }
                        else
                        {
                            temp[i] += base_dp[child][i];
                        }
                    }
                }
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        adj.clear();
        adj.resize(n);

        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            first--;
            second--;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        base_dp.clear();
        base_dp.resize(n);
        cross_dp.clear();
        cross_dp.resize(n);
        subtree.resize(n);
        dfs_size(0, -1);

        int centroid = find_centroid(0, -1, n);
        dfs(centroid, -1);
        int res = 0;
        for (auto a : base_dp)
        {
            int size = a.size();
            for (int i = 0; i < size; i++)
            {
                int pairs = a[i];
                int dist = i;
                int curr = (dist + k - 1) / k;
                curr *= pairs;
                res += curr;
            }
        }

        for (int i = 0; i < cross_dp.size(); i++)
        {

            int pairs = cross_dp[i];
            int dist = i;
            int curr = (dist + k - 1) / k;
            curr *= pairs;
            res += curr;
        }

        cout << res << endl;
    }

    return 0;
}

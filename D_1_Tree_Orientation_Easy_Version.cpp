#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    i think the base case for no is that if arr[i][j] == arr[j][i] == 1 then no because it will lead to cycle formation.. ofc i != j

    there will be some nodes whose only set thing is going to be arr[i][i] those are the leaf nodes..

    and all the nodes above this will have this all the bits that are set in this..

    i.e., generally speaking all the set bits in child bit is going to be set in parent as well..

    else ok = false..

    now how do i move up from this child nodes..

    there are going to be some candidates obv :

        among those candidates i need to choose some ..


    AMONG THESE CANDIDATES THERE WILL BE SOME NODES THAT WILL CONTAIN THESE OTHER CANDIDATES i.e., :


        THERE ARE SOME SUPER NODES THAT IS SOME SUPER PARENT OF THIS NODE, we will remove those nodes

        among the candidates if there is some other current candidate then remove them..

        now after we are done doing this we will either have proper graph where all necessary are connected

        or some cycles these both conditions can be checked using dsu if everything's fine then return these edges else no.. .




*/

class DSU
{
private:
    vector<int> parent, sz;
    int components;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        components = n;

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        // union by size
        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        components--;

        return true;
    }

    int getComponents()
    {
        return components;
    }

    int getSize(int x)
    {
        return sz[find(x)];
    }
};

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
        vector<string> childs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> childs[i];
        }
        queue<int> leafs;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (auto a : childs[i])
            {
                if (a == '1')
                    count++;
            }

            if (count == 1)
            {
                leafs.push(i);
            }
        }
        vector<set<int>> adj(n);
        while (!leafs.empty())
        {
            int curr_node = leafs.front();

            leafs.pop();
            if (vis[curr_node] == 1)
                continue;
            vis[curr_node] = 1;
            vector<int> candidates;
            set<int> temp;
            for (int i = 0; i < n; i++)
            {
                if (i == curr_node)
                    continue;
                if (childs[i][curr_node] == '1')
                {

                    candidates.push_back(i);
                    temp.insert(i);
                }
            }
            set<int> super_parents;
            for (auto a : candidates)
            {

                for (auto b : candidates)
                {
                    if (a != b)
                    {
                        if (childs[a][b] == '1')
                        {
                            super_parents.insert(a);
                        }
                    }
                }
            }

            for (auto a : super_parents)
            {
                temp.erase(a);
            }
            for (auto a : temp)
            {

                adj[a].insert(curr_node);
                if (vis[a])
                    continue;
                else
                    leafs.push(a);
            }
        }
        DSU du(n);
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            for (auto a : adj[i])
            {
                bool curr = du.unite(i, a);
                if (curr == false)
                {
                    ok = false;
                    break;
                }
            }
            if (ok == false)
                break;
        }
        for (int i = 0; i < n; i++)
        {
            if (childs[i][i] != '1')
            {
                ok = false;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto child : adj[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (childs[child][j] == '1')
                    {
                        // it should be child of par as well.
                        if (childs[i][j] == '0')
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok == false)
                    break;
            }
            if (ok == false)
                break;
        }
        int curr_comp = du.getComponents();
        if (curr_comp != 1)
            ok = false;
        if (ok == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++)
            {
                for (auto a : adj[i])
                {
                    cout << i + 1 << " " << a + 1 << endl;
                }
            }
        }
    }
    return 0;
}
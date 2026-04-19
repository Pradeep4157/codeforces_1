#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    are we going to go back to some node to go to some other node to red cost..

    4 7 9
    5 6 8

    if we reach 6 first

    1st case :

        3 * 1 + 5 * 3 = 18

        3 * 1  + 3 * 1 + 2 * 2 = 10


        so it can happen..


    so first we need to find min cost to reach from A -> B


    then we use this to find min cost using dfs.. 


    so i start from any node and vis all 


    so for every node i have 2 choices ; 

        either i reach second node directly 




*/
// class DSU
// {
// public:
//     vector<int> parent, size;

//     DSU(int n)
//     {
//         parent.resize(n);
//         size.resize(n, 1);

//         for (int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
//     }

//     int find(int x)
//     {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     bool unite(int x, int y)
//     {
//         int px = find(x);
//         int py = find(y);

//         if (px == py)
//             return false;

//         if (size[px] < size[py])
//         {
//             parent[px] = py;
//             size[py] += size[px];
//         }
//         else
//         {
//             parent[py] = px;
//             size[px] += size[py];
//         }
//         return true;
//     }
// };
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr = abs(arr[i] - arr[j]) * abs(i - j);
            pq.push({curr, i, j});
        }
    }
    DSU du(n);
    int res = 0;
    set<int> st;
    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();
        int first = top[1];
        int second = top[2];
        bool ok = false;
        int val = top[0];
        bool curr = du.unite(first, second);
        if (curr)
            res += top[0];
    }
    cout << res << endl;

    return 0;
}

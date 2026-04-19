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
    int n, m;
    cin >> n >> m;
    set<int> st;
    st.insert(1);
    set<int> res;
    res.insert(1);
    vector<pair<int, int>> arr;
    map<int, set<int>> mp;
    for (int i = 0; i < m; i++)
    {
        int first, second;

        cin >> first >> second;
        mp[first].insert(second);
        arr.push_back({first, second});
    }
    vector<bool> vis(n + 1, false);
    while (!st.empty())
    {
        int front = *st.begin();
        res.insert(front);
        st.erase(st.begin());
        if (vis[front])
        {
            continue;
        }
        vis[front] = 1;
        if (mp.find(front) == mp.end())
            continue;
        for (auto &a : mp[front])
        {
            if (vis[a] == false)
            {
                st.insert(a);
            }
        }
    }
    cout << (res.size()) << endl;
    return 0;
}

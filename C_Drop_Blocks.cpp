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
        map<int, int> mp;        // this will store which block current i is in
        map<int, set<int>> mp_1; // this will store elements in current lev..
        int curr_zero = 0;       // this will tell how much has everyone dec..
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            mp[i] = 0;
            mp_1[0].insert(i);
        }
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int x;
                cin >> x;
                int curr_lev = mp[x];
                mp_1[curr_lev].erase(x);
                if (mp_1[curr_lev].size() == 0)
                {
                    mp_1.erase(curr_lev);
                }
                mp_1[curr_lev + 1].insert(x);
                mp[x]++;

                int curr_zero_level_size = mp_1[curr_zero].size();
                if (curr_zero_level_size == 0)
                {
                    curr_zero++;
                }
            }
            else
            {
                int y;
                cin >> y;
                int curr = 0;
                for (auto it = mp_1.lower_bound(y + curr_zero); it != mp_1.end(); it++)
                {
                    curr += it->second.size();
                }
                cout << curr << endl;
            }
        }
    }
    return 0;
}

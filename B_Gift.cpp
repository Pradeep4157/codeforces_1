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
        map<int, set<int>> mp;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int ele;
                cin >> ele;
                mp[ele].insert(i + 1);
            }
        }
        for (int i = 1; i <= n; i++)
        {

            cout << mp[i].size() << " ";
            // cout << a.first << ' ';
            for (auto b : mp[i])
            {
                cout << b << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

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
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            mp[ele]++;
        }
        vector<string> res(2);
        if (mp.size() >= n)
        {
            res[0] = "Yes";
        }
        else
            res[0] = "No";

        if (mp.size() >= m)
        {
            res[1] = "Yes";
        }
        else
            res[1] = "No";
        for (auto a : res)
        {
            cout << a << endl;
        }
    }
    return 0;
}

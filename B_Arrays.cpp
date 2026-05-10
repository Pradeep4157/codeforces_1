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
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int ele;
                cin >> ele;
                arr[i].push_back(ele);
            }
        }
        int x, y;
        cin >> x >> y;
        cout << (arr[x - 1][y - 1]) << endl;
    }
    return 0;
}

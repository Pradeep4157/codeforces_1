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
    vector<vector<char>> arr(n, vector<char>(m, '.'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                arr[i][j] = '#';
            }
        }
    }
    for (auto a : arr)
    {
        for (auto b : a)
            cout << b;
        cout << endl;
    }
    return 0;
}

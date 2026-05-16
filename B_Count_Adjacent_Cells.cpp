#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n, m;
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {

        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m, 4));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int adj_x = i + dx[k];
                    int adj_y = j + dy[k];
                    if (!is_valid(adj_x, adj_y))
                    {
                        arr[i][j]--;
                    }
                }
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}

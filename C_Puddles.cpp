#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n, m;
bool is_corner(int i, int j)
{
    return (i == 0 || i == n - 1 || j == 0 || j == m - 1);
}
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
bool dfs(int i, int j, vector<vector<char>> &arr, vector<vector<bool>> &vis)
{

    if (!is_valid(i, j) || vis[i][j] || arr[i][j] == '#')
        return false;
    vis[i][j] = 1;

    bool res = is_corner(i, j);
    for (int k = 0; k < 4; k++)
    {
        int next_x = dx[k] + i;
        int next_y = dy[k] + j;
        res |= dfs(next_x, next_y, arr, vis);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int res = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == false && (arr[i][j] == '.'))
            {

                bool curr = dfs(i, j, arr, vis);
                if (curr == false)
                    res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};
int n, m;
bool is_valid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            else if (arr[i][j] == 'G')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, -1)));
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        int curr_x = curr.first;
        int curr_y = curr.second;
        if (arr[curr_x][curr_y] == '#')
            continue;

        if (curr_x == end_x && curr_y == end_y)
        {
            break;
        }
        if (arr[curr_x][curr_y] == '.' || (arr[curr_x][curr_y] == 'S'))
        {
            for (int i = 0; i < 4; i++)
            {
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];
                if (is_valid(new_x, new_y) && (dp[new_x][new_y][i] == -1))
                {
                    dp[new_x][new_y][i] = 1;
                    par[new_x][new_y] = {curr_x, curr_y};
                    q.push({new_x, new_y});
                }
            }
        }
        else if (arr[curr_x][curr_y] == 'o')
        {

            int par_x = par[curr_x][curr_y].first;
            int par_y = par[curr_x][curr_y].second;
            int new_x, new_y;
            if (par_x == curr_x)
            {
                // left or right..
                int diff = par_y - curr_y;
                new_x = curr_x;
                new_y = curr_y - diff;
            }
            else
            {
                // left or right..
                int diff = par_x - curr_x;
                new_x = curr_x - diff;
                new_y = curr_y;
            }

            if (is_valid(new_x, new_y))
            {
                par[new_x][new_y] = {curr_x, curr_y};
                q.push({new_x, new_y});
            }
        }
        else if (arr[curr_x][curr_y] == 'x')
        {
            // we cant move in same dirr..
            int par_x = par[curr_x][curr_y].first;
            int par_y = par[curr_x][curr_y].second;
            vector<int> valid = {1, 1, 1, 1};
            if (curr_x == par_x)
            {
                if (par_y - curr_y < 0)
                {
                    valid[0] = 0;
                }
                else
                    valid[1] = 0;
            }
            else
            {
                if (par_x - curr_x < 0)
                {
                    valid[2] = 0;
                }
                else
                    valid[3] = 0;
            }
            for (int i = 0; i < 4; i++)
            {
                if (valid[i] == 0)
                    continue;
                int new_x = curr_x + dx[i];
                int new_y = curr_y + dy[i];
                if (is_valid(new_x, new_y) && (dp[new_x][new_y][i] == -1))
                {
                    dp[new_x][new_y][i] = 1;
                    par[new_x][new_y] = {curr_x, curr_y};
                    q.push({new_x, new_y});
                }
            }
        }
    }
    for (auto a : par)
    {
        for (auto b : a)
        {
            cout << b.first << ":" << b.second << "  ";
        }
        cout << endl;
    }
    if (par[end_x][end_y].first == -1)
    {
        cout << "No" << endl;
        return 0;
    }

    string res;

    cout << "Yes" << endl;
    for (int i = 0; i < 1e6; i++)
    {
        if (end_x == start_x && end_y == start_y)
            break;
        
        int par_x = par[end_x][end_y].first;
        int par_y = par[end_x][end_y].second;
        if (par_x == end_x)
        {
            int diff = par_y - end_y;
            if (diff < 0)
            {
                res += 'L';
            }
            else
                res += 'R';
        }
        else
        {
            int diff = par_x - end_x;
            if (diff < 0)
            {
                res += 'U';
            }
            else
                res += 'D';
        }
        cout << end_x << ":" << end_y << endl;
        end_x = par_x;
        end_y = par_y;
    }
    return 0;
}

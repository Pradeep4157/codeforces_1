#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    will they stop changing after some point ?

    -> No

    even if there is one black cell that is going to color

    all the nei white cells and it will become black..

#.#....
###....
..#....
.......
....#..



so at every step some nodes are going to change..


unless the whole array is black or white they are just going to

change once or zero times and then they will remain the same..

but for others..

it is going to be like bfs where node becomes black  at some points..


once it becomes black at every alt step it is going to be black..

x,x + 2,x + 4,x + 6...

why ?

because if at x it became == black and the adj black that

made this cell white became white, then at x + 1 it will become white

and the adj one that made it black will become black because of this cell.

so once it is vis that is going to be the thing..

so even dist will be black else white..


*/
int n, m;

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
bool is_valid(int x, int y)
{
    return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}
int modPow(int a, int b, int mod)
{
    int res = 1;
    a %= mod;

    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}
vector<string> find(vector<string> arr)
{
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '#')
            {
                temp += '.';
                continue;
            }
            bool found = false;
            for (int k = 0; k < dx.size(); k++)
            {
                int nei_i = i + dx[k];
                int nei_j = j + dy[k];
                if (is_valid(nei_i, nei_j))
                {
                    if (arr[nei_i][nei_j] == '#')
                    {
                        found = 1;
                        break;
                    }
                }
            }
            if (found == false)
            {
                temp += '.';
            }
            else
                temp += '#';
        }
        res[i] = temp;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {

        cin >> n >> m;
        vector<string> arr(n);
        bool black_found = false, white_found = false;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            for (auto a : arr[i])
            {
                if (a == '#')
                    black_found = 1;
                else
                    white_found = 1;
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                {

                    q.push({i, j});
                }
            }
        }
        int time = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        while (!q.empty())
        {
            int SIZE = q.size();
            for (int z = 0; z < SIZE; z++)
            {
                pair<int, int> curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                if (dp[i][j] != -1)

                    continue;

                dp[i][j] = time;
                for (int k = 0; k < dx.size(); k++)
                {
                    int new_i = i + dx[k];
                    int new_j = j + dy[k];
                    if (!is_valid(new_i, new_j))
                        continue;
                    if (dp[new_i][new_j] == -1)
                    {
                        // if (vis[new_i][new_j])
                        //     continue;
                        vis[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
            if (!q.empty())
                time++;
        }
        vector<string> res = arr;
        for (int i = 0; i < time; i++)
        {

            res = find(res);
        }
        if (time & 1)
            time++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << res[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so this is of the type where we first find the max len of susbseq...

    and then mostly using some other recursion find that path..




*/
int n, m;
vector<vector<int>> dp;
vector<int> first, second;
vector<int> ans;
int recursion(int i, int j)
{
    if (i == n || j == m)
        return 0;
    // either we skip i.
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = recursion(i + 1, j);
    // or we skip j..
    res = max(res, recursion(i, j + 1));
    // or if both are same then we inc..
    if (first[i] == second[j])
        res = max(res, 1 + recursion(i + 1, j + 1));
    return dp[i][j] = res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    first.clear();
    second.clear();
    first.resize(n), second.resize(m);
    for (int i = 0; i < n; i++)
        cin >> first[i];
    for (int i = 0; i < m; i++)
        cin >> second[i];
    dp.assign(n, vector<int>(m, -1));

    int res = recursion(0, 0);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (first[i] == second[j])
        {
            ans.push_back(first[i]);
            i++;
            j++;
        }
        else if (i + 1 < n && dp[i + 1][j] >= dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << res << endl;
    for (auto a : ans)
        cout << a << ' ';
    cout << endl;
    return 0;
}

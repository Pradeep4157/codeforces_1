#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
string s, t;
int n, m;
int dp[5000][5000];
int recursion(int i, int j)
{
    if (i >= n)
        return (m - j);
    if (j >= m)
        return (n - i);
    if (dp[i][j] != -1)
        return dp[i][j];
    // either i remove first char..
    int res = 1 + recursion(i + 1, j);
    // or i insert a char..
    res = min(res, 1 + recursion(i, j + 1));
    // or i am replacing..
    res = min(res, 1 + recursion(i + 1, j + 1));
    // or both of them are already equal..
    if (s[i] == t[j])
    {
        res = min(res, recursion(i + 1, j + 1));
    }
    return dp[i][j] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    n = s.size();
    m = t.size();
    int res = recursion(0, 0);
    cout << res << endl;
    return 0;
}

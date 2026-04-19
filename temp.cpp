#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    upper limit is that i make

    all the elemnets diff.

    i have to keep track of

    last change that i made

    if this current ele's prev

    freq is after that change

    and there is no ele in between

    that is unique in the whole

    array then i will have to change

    this

    this can be optimized using

    lower bounds..

    else i will either change

    and move else i will not change

    and move..






*/
vector<vector<int>> dp;
int n;
vector<int> arr;
set<int> st;
int recursion(int i, int prev_change)
{
    if (i == n + 1)
        return 0;
    // either i have to change..
    bool ok = 1;
    if (dp[i][prev_change] != -1)
        return dp[i][prev_change];
    for (int j = i - 1; j >= 0; j--)
    {
        if (j <= prev_change || st.count(arr[j]))
            break;
        if (arr[i] == arr[j])
        {
            ok = false;
            break;
        }
    }
    int res = LLONG_MAX;
    if (ok)
    {
        // we can skip this index..
        res = recursion(i + 1, prev_change);
    }
    res = min(res, 1 + recursion(i + 1, i));
    return dp[i][prev_change] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.clear();
        arr.resize(n + 1);
        map<int, int> mp;
        st.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        for (auto a : mp)
        {
            if (a.second == 1)
            {
                st.insert(a.first);
            }
        }
        dp.assign(n + 2, vector<int>(n + 2, -1));
        int res = recursion(1, 0);
        cout << res << endl;
    }
    return 0;
}
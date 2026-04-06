#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so for each n ribs we have some satisfies..

    and we will see what all chars are ok

    for this index..

    now for each string from 1..m

    if some strings have this in ith from 1..n

    then yes else no..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int m;
    cin >> m;
    vector<set<char>> st(n);
    vector<string> alls(m);
    for (int i = 0; i < m; i++)
    {
        string curr;
        cin >> curr;
        alls[i] = curr;
        int size = curr.size();
        for (int j = 0; j < n; j++)
        {
            if (arr[j].first == size)
            {
                st[j].insert(curr[arr[j].second - 1]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int size = alls[i].size();
        bool ok = 1;
        if (size != n)
        {
            cout << "No" << endl;
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (!st[j].count(alls[i][j]))
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}

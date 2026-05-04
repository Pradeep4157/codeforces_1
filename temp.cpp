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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int curr = 0;
        vector<int> suffix(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == t[i])
                curr++;
            suffix[i] = curr;
        }
        curr = 0;
        bool found = false;
        if (suffix[0] == n)
        {
            cout << "Yes" << endl;
            cout << 0 << endl;
            continue;
        }
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1' && (s[i] != t[i]))
            {
                int prev = i;
                int next = n - i - 1;
                if (next)
                {
                    if (suffix[i] < next)
                        continue;
                }
                // next all are same..
                // now prev all should be diff.
                if (prev != curr)
                {
                    continue;
                }
                index = i;
                break;
            }
            if (s[i] != t[i])
                curr++;
        }
        if (index == -1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << index << endl;
        }
    }
    return 0;
}

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
        string s;
        cin >> s;
        int res = 0;
        for (auto a : s)
        {
            if (a == '(')
                res++;
            else
                res--;
        }
        cout << ((res == 0) ? "YES" : "NO") << endl;
    }
    return 0;
}

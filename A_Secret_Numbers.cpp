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
    int t = 1;
    while (t--)
    {
        string s;
        cin >> s;
        string res;
        for (auto a : s)
        {
            if (a >= '0' && (a <= '9'))
            {
                res += a;
            }
        }
        cout << res << endl;
    }
    return 0;
}

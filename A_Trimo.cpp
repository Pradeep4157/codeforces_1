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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res;
    for (auto a : s)
    {
        if (a == 'o' && (res.empty()))
            continue;
        else
            res += a;
    }
    cout << res << endl;
    return 0;
}

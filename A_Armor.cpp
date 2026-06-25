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
        int a, d;
        cin >> a >> d;
        if (a <= d)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

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
    bool ok = 1;
    if (n < 3)
        ok = false;
    if (n > 18)
        ok = false;
    cout << ((ok) ? "Yes" : "No") << endl;
    return 0;
}

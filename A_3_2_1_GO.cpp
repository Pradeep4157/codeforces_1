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
    while (n)
    {
        if (n == 0)
            break;
        cout << n;
        if (n > 1)
            cout << ",";
        n--;
    }
    return 0;
}

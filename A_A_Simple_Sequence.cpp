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
        if (n == 2)
        {
            cout << n << " " << n - 1 << endl;
        }
        else
        {
            cout << 2 << " ";
            for (int i = n; i >= 1; i--)
            {
                if (i == 2)
                    continue;
                else
                    cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

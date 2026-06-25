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
        int n;
        cin >> n;
        char type;
        cin >> type;
        int idx = type - 'A';
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s[idx] == 'o')
                found = 1;
        }
        cout << (found ? "Yes" : "No") << endl;
    }
    return 0;
}

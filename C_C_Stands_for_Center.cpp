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
        int res = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'C')
            {
                res++;
                int right = n - i - 1;
                int left = i;
                int curr = min(left, right);
                res += curr;
            }
        }
        cout << res << endl;
    }
    return 0;
}

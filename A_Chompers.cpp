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
        int n;
        cin >> n;
        int size = s.size();
        int start = n;
        int end = size - n - 1;
        for (int i = start; i <= end; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}

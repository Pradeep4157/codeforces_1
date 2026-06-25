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
        string s = "HelloWorld";
        int x;
        cin >> x;
        s.erase(x - 1, 1);
        cout << s << endl;
    }
    return 0;
}

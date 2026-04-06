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
    string s;
    cin >> s;
    int n = s.size();
    if (n % 5)
    {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
    return 0;
}

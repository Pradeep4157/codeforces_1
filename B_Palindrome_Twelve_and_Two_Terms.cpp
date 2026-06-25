#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    digit dp:

    i will add some digits from len = 1..size(n) / 2

    and then i will either check that

    or add some middle ele and check that as well..




*/
vector<int> first = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 22, 11};

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
        int rem = n % 12;
        int b = n - first[rem];
        if (b >= 0)
        {
            cout << first[rem] << " " << b << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
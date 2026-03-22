#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so 2n len 1..n and n zeroes..

    i,j (1 based.)

    1 if they are same else 0..

    they are same only if both are zero..

    return k such that arr[k] = 0.. in n + 1 queries..



*/
bool query(int first, int second)
{
    cout << "? " << first << " " << second << endl;
    int res;
    cin >> res;
    return (res == 1);
}
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
        int size = n * 2ll;
        int res = -1;
        for (int i = 1; i <= n; i++)
        {
            int first = size;
            int second = i;
            bool curr = query(first, second);
            if (curr == 1)
            {
                res = first;
                break;
            }
        }
        if (res == -1)
        {
            bool curr = query(size, n + 1);
            if (curr == 1)
                res = n + 1;
            else
                res = n + 2;
        }
        cout << "! " << res << endl;
    }
    return 0;
}

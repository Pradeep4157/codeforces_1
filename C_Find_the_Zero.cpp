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
        for (int i = 1; i < size - 1; i += 2)
        {
            bool curr = query(i, i + 1);
            if (curr == 1)
            {
                res = i;
                break;
            }
        }
        if (res == -1)
        {
            // either last 2 pairs are 10,10 or 11,00
            // the last first pair is already checked they are not equal..
            // only so it is def 10 or 11 so if 10,00 is the case then i check first with both if not then second one is answer
            // if 11,00 in this case just choosing second wont work..
        }
        cout << "! " << res << endl;
    }
    return 0;
}

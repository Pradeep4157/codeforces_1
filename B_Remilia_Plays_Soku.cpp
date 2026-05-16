#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if n > 2 then she will always move in opp direction of

    reimu and save till kth second..

    one thing is certain that she will

    move in opp direction of reimu always

    else if she moves in her direction then

    she gets caught earlier..




*/
int find(int x1, int x2, int k, int n)
{
    int res = abs(x1 - x2);
    res = min(res, n - abs(x1 - x2));
    res += k;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, x2, k;
        cin >> n >> x1 >> x2 >> k;
        bool left = false;
        if (n == 2)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 3)
        {
            int diff = abs(x1 - x2);
            if (diff >= 2)
            {
                cout << 1 << endl;
                continue;
            }
        }
        x1--;
        x2--;
        int cw = (x2 - x1 + n) % n;
        int ccw = (x1 - x2 + n) % n;

        if (cw < ccw)
        {

            left = false;
        }
        else
        {
            left = true;
        }
        int res = find(x1, x2, k, n);
        // for (int i = 0; i < n; i++)
        // {
        //     {
        //         // i choose to go towards right side..
        //         if (i >= x1)
        //         {
        //             int curr = i - x1;
        //             if (curr <= k)
        //             {
        //                 // lets see when does she reach here..
        //                 int second = abs(i - x2);
        //                 second = min(second, n - x2 + i);
        //                 second = min(second, n - i + x2);
        //                 res = max(res, second);
        //             }
        //         }
        //         else
        //         {
        //             int curr = n - x1;
        //             curr += i;
        //             if (curr <= k)
        //             {
        //                 int second = abs(i - x2);
        //                 second = min(second, n - x2 + i);
        //                 second = min(second, n - i + x2);
        //                 res = max(res, second);
        //             }
        //         }
        //     }
        //     {
        //         // i chose to move left..
        //         if (i < x1)
        //         {
        //             int curr = x1 - i;
        //             if (curr <= k)
        //             {
        //                 int second = abs(i - x2);
        //                 second = min(second, n - x2 + i);
        //                 second = min(second, n - i + x2);
        //                 res = max(res, second);
        //             }
        //         }
        //         else
        //         {
        //             int curr = x1;
        //             curr += n - i;
        //             if (curr <= k)
        //             {
        //                 int second = abs(i - x2);
        //                 second = min(second, n - x2 + i);
        //                 second = min(second, n - i + x2);
        //                 res = max(res, second);
        //             }
        //         }
        //     }
        // }
        cout << res << endl;
    }
    return 0;
}

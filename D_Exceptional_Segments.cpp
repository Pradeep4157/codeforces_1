#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    the idea is that xorr of 2^n..2^(n + 1) - 1 is zero..

    so i need to find the no of 2^(n + 1) - 1 >= x && <= n

    and no of 2^n <= x  >= 1


    xorr of any 4 cons numbers is 0 when first element is even..

    so we take these 4 len ....from 2...

    there are 2 starts one that start with 2 len >= x

    and one that





*/
const int mod = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n <= 3)
        {
            if (n == 3)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }
        if (n == 4)
        {
            if (x <= 3)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            continue;
        }
        int res = 0;

        {
            // here we start from 2...
            if (x >= 2)
            {
                int start = 2;
                int left = (x - start) / 4;
                int last_start = start + left * 4;
                int first_end = last_start + 3;
                left++;
                int right = 0;
                if (first_end <= n)
                {
                    right = (n - first_end) / 4;
                    right++;
                }
                left %= mod;
                right %= mod;
                res += (left * right);
                res %= mod;
            }
            if (x >= 4)
            {
                int start = 4;
                int left = (x - start) / 4;
                int last_start = start + left * 4;
                int first_end = last_start + 3;
                left++;
                left++;
                left %= mod;
                int right = 0;
                if (first_end <= n)
                {
                    right = (n - first_end) / 4;
                    right++;
                }
                right %= mod;
                res += (left * right);
                res %= mod;
            }
            else
            {

                int start = 4;
                int left = 0;
                int last_start = start + left * 4;
                int first_end = 3;
                left++;
                left %= mod;
                int right = 0;
                if (first_end <= n)
                {
                    right = (n - first_end) / 4;
                    right++;
                }
                right %= mod;
                res += (left * right);
                res %= mod;
            }
        }

        cout << res << endl;
    }
    return 0;
}
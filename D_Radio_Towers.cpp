#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    denominator is constant that is 2^n..

    i.e., either we make it or we dont make it.. for all the n

    so 0 and n + 1 shouldnt get any signal..

    i.e., the range should strictly end at 1 and n..

    one way is that i brute force the possibilities..

    i end the circle here so d = 1,3,5,7,.....

    and merge with dp[i - curr_diameter]

    the structure is right, just we need to optimize the n^2 loop:

    the sequence is 1,3,5,7,...

    more like 0,2,4,6,8....









*/
int mod = 998244353;

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int modInverse(int y)
{
    return power(y, mod - 2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> dp(n + 2);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            dp[i] += dp[i - 1];
            dp[i] %= mod;
            if (i - 2 > 0)
                dp[i] += dp[i - 2];
            dp[i] %= mod;
        }
        int numerator = dp[n];
        int denominator = power(2, n);
        numerator *= modInverse(denominator);
        numerator %= mod;
        cout << numerator << endl;
    }
    return 0;
}

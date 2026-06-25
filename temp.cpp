#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    n elements and arr[i] <= m

    all the adj elements should not be co prime..

    but the gcd of whole array should be 1..

    so obv no arr[i] == 1..

    let say i put any value from 2...m as arr[0]..



    2,2
    2,4
    2,6
    4,2
    6,2

    for all n >= 2 ..

        the main condition is that first and last element should be co prime and all the middle elements should have factor of first and last elements.

        so we can rearrange these middle elements however we want,


            what are going to be in middle :

                so the count of middle elements is going to be :

                    cnt = m / left * right

                and since we can rearrarge these elements however we want and can take any number of these element..

                    so the possibilities for each position = cnt

                res += positions ^ cnt


    i cant simply use left * right as min number , we can start lower than that..

    should the middle elements have all the factors of left and right or even if only some are present then its fine ?

        Eg : left = 6 (2, 3) , right = 35(5, 7)

        now if the middl is 10 that also works ..

    so the range of elements increases..

    the range can include :

        i take any non empty subsequence of prime factors from left and any set of non empty subsequence from right and add that to possiblities..

        what's the max number of prime factors each will have :

            2 * 3 * 5 , 7 * 9
                        7,3

            at max there are going to be 21 combinations..

                so combinations are way too low since both cannot have any common thing :

            but this might also cause some overlap ...

                lets say i take 2, 7 = {14, 28, 42, 56, }

            instead what i can do is that :

                iterate from 1...m :

                    if the number has some factor that is in both the set then yes  else no..




                [2,6,3]
                [2,12,3]
                [2,10,5]
                [2,6,9]
                [2,12,9]
                [3,6,2]
                [3,12,2]
                [3,6,4]
                [3,12,4]
                [3,6,8]
                [3,12,8]
                [3,6,10]
                [3,12,10]
                [4,6,3]
                [4,12,3]




                263141891
                877339567

        
    6,10,21,35

        so some factor which i select should be present in all the mid elemnents...

    


*/

int n, m;

const int mod = 998244353;
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (1LL * res * a) % mod;
        }
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
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
        cin >> n >> m;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }

        int res = 0;
        vector<int> power_dp(m + 1);
        for (int i = 0; i <= m; i++)
        {
            int curr = binpow(i, n - 2);
            curr %= mod;
            power_dp[i] = curr;
        }
        for (int left = 1; left <= m; left++)
        {
            for (int right = 1; right <= m; right++)
            {
                int curr_gcd = __gcd(left, right);
                if (curr_gcd != 1)
                    continue;
                int curr = 0;
                int cnt = 0;
                for (int ele = 1; ele <= m; ele++)
                {
                    bool left_found = false, right_found = false;
                    if (__gcd(left, ele) > 1)
                        left_found = 1;
                    if (__gcd(right, ele) > 1)
                        right_found = 1;
                    if (left_found && right_found)
                        cnt++;
                }
                if (n == 2)
                {
                    // since there is no middle element there is only 1 way that there's nothing between and left on left and right on right..
                    res++;
                    res %= mod;
                    continue;
                }
                curr = power_dp[cnt];
                res += curr;
                res %= mod;
            }
        }
        res %= mod;
        cout << res << endl;
    }
    return 0;
}

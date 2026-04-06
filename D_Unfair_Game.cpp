#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so till some power of 2 we can freely use all the even numbers.

    but in the last power of 2 that is valid some odd

    numbers before that will be invalid..

    we need to remove them and return the rem..

    so ans is 2^x this is the last thing till where it is valid..

    before that we will remove the invalid odd ones..

    and return the ans..

    not even all even numbers from

    1-1
    2-2
    3-3
    4-3
    5-4
    6-4
    7-5
    8-4
    9-5
    10-5
    11-6
    12-5
    13-6
    14-6
    15-7
    16-5
    17-6
    18-6
    19-7
    20-6
    21-7
    22-7
    23-8
    24-6


    all odds are bad except start + 1..


    from start + 1...end only the numbers are valid who are when keep dividing / 2 till we reach 1 only 1 time we get odd number..

    else  bad number..

    one eg is start + 1..

    that we do - 1 and we get power of 2 so the no of good numbers are start,end,start + 1,


    it is all power of 2 from 2...start + 1..

    for all these numbers we see if they are within n if they are then do res--

    else continue..


    now we stop at some power of 2 , it is either of 2 reasons :

    i) we  dont have enough k :

        in this case we can allow only 1 odd swap thing from start...end

        which is already implmented..

    ii) else the other reason is that we have reached end..

        the upper bound is the 2 power of start..

        this maybe can be found using dp..



        at 2 power of 0 with 1 step it is possible.. .

        from i = 1 ...28...
            for j = 1..i
                dp[i][j] = dp[i - 1][j - 1] + 1.





*/
int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r > n - r)
        r = n - r; // optimization

    int res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
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
        int n, k;
        cin >> n >> k;
        int msb = 0;
        int number = 1;
        while (true)
        {
            if (number == n)
                break;
            msb++;
            number <<= 1;
        }

        int res = 0;
        // now for each msb we will find the ncr for that bit..
        if (msb + 1 <= k)
            res++;
        for (int i = msb - 1; i >= 0; i--)
        {

            for (int one_count = 0; one_count <= i; one_count++)
            {
                int curr = k - 1; // since one op for msb..
                // for these ones it will take 2 ops..
                int rem_digits = i;
                int zero_count = rem_digits - one_count;
                curr -= (zero_count);
                curr -= (2 * one_count);
                // cout << i << ":" << one_count << ":" << zero_count << " = " << curr << endl;
                if (curr < 0)
                    continue;

                // else this is valid..
                // so among the rem digits we will do rem_digits C one_count
                res += nCr(rem_digits, one_count);
            }
        }
        cout << n - res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we are given the number of T,H and U shaped blocks count..

    we have to fit these into : n * 3 grid

    they can be rotated by 90 deg but i dont know

    if that makes it any better..

    yes it doess for  T.

    first best is that we merge T with U because

    both combined takes 4 lines..

    T,U = 4
    T,H = 5
    H,U = 6
    T,T = 5
    H,H = 6
    U,U = 6

    first we will try to merge T with U

    then T with H and T with T

    then the remaining each takes 3 no matter what..

    its better to merge T with T first because

    we will save a lot of space

    first T is going to take 3 space..

    then all the other T's are going to take 2 spaces..


    2T, 1H can be merged together for a cost of





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int t, h, u;
        cin >> t >> h >> u;
        int res = 0;
        int mini = min(t, u);
        t -= mini;
        u -= mini;
        res += (mini * 4);
        {
            int can_do = t;
            can_do /= 2;
            can_do = min(can_do, h);
            h -= can_do;

            t -= (2 * can_do);
            res += (7 * can_do);
        }
        if (t > 1)
        {
            // merge all ts together..
            res += 3;
            t--;
            // now all the t's are going to take 2 spaces..
            res += (2 * t);
            t = 0;
        }
        else
        {
            // t can be 1 or zero..
            mini = min(t, h);
            res += (mini * 5);
            t -= mini;
            h -= mini;
        }
        res += (3 * (t + u + h));
        cout << res << endl;
    }
    return 0;
}

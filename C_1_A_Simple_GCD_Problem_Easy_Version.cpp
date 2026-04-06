#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we can only dec ai..

    such that all gcd's remain same of len >= 2..

    brute force on all l ?

    only l and l + 1 matters ?

    no l, l - 1 also matters..


    4,6,...

    i would think that i can change 4

    but any number that i change to also should

    give same lcm as l was giving to l - 1...

    so i = 0 depends on 1. and i = n - 1 depends on n - 2.

    remaining dep on i - 1, i + 1..


    so any number from 1...ai such that

    it gives same gcd ..


    for i = 1.. n - 1








*/
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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].second;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                int first = __gcd(arr[i].first, arr[i + 1].first);
                if (first == arr[i].first)
                    continue;
                arr[i].first = first;
                res++;
            }
            else if (i == n - 1)
            {
                int second = __gcd(arr[i].first, arr[i - 1].first);
                if (second == arr[i].first)
                    continue;
                arr[i].first = second;
                res++;
            }
            else
            {
                int first = __gcd(arr[i].first, arr[i - 1].second);
                int second = __gcd(arr[i].first, arr[i + 1].first);

                bool ok1 = false, ok2 = false;
                {
                    // if i choose to make this second..
                    // then second with arr[i - 1].first should have same gcd as arr[i].first
                    int prev_gcd_1 = first;
                    int curr_gcd_1 = __gcd(second, arr[i - 1].second);
                    if (curr_gcd_1 == prev_gcd_1)
                    {
                        // we can make arr[i] == second..
                        if (second < arr[i].second)
                            arr[i].first = min(arr[i].first, second);
                        ok1 = 1;
                    }
                }
                {
                    // if i choose to make this first..
                    int prev_gcd_2 = second;
                    int curr_gcd_2 = __gcd(arr[i + 1].first, first);
                    if (curr_gcd_2 == prev_gcd_2)
                    {
                        if (first < arr[i].second)
                            arr[i].first = first;
                        ok2 = 1;
                    }
                }

                ok1 = false;
                if (arr[i].first < arr[i].second)
                    ok1 = 1;
                if (ok1)
                    res++;
            }
        }

        cout << res << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    k is given..

    array of n numbers is given..

    we are also given range p...q

    we select some subarray of size atleast k

    and we select some number m from range p...q

    and then set all the values in the subarray

    as arr[i] % m

    we need to minimize the total sum of the  array..

    maybe k doesnt matter..

    because we might do operations in such a way

    that smaller elements dont get affected by larger mods..

    {6,20}


    i thought of using 3,5

    if i use 5 first then  1,20 and i cant use 3

    if i use 3,5

    0,2 and here also i cant use 5 so

    we cant ignore k ..

    the upper bound is that i take p and do mod with

    the whole array..

    we dont need to consider all elements from p...q

    its just p and q..

    now there are 2 things :

    Either we take k len / we increase more than k len..

    so first we find best for len >= 1..

    then for every index we find that if we end at this index..

    then we take mod p or q and then i - k th index we can merge with the same mod single or more than 1 len thing..

    else if we choose to take the opposite one then we need to take that atleast k one..

    that is if i am merging p with p i will merge with single one

    else if i am merging p with q or vice versa i will have to merge with k len one..

    but this is not fully correct ..

    we will have to create dp_1 and dp_2 parallely...

    it allows p and q both getting applied on same window ..

    so at the end of the window i have done for either p / q..

    now either i apply p -> q / q -> p..

    in p -> q :

        we can merge this with dp1[i - k] first / second and dp_p_q[i - k]

    in q -> q :

        we can merge this with dp[i - k] first / second and dp_q_p[i - k]


    now for building dp_p_q for this index i apply % p followed by % q..

        and then i merge this state with either dp_1 i - 1 first / second or dp_p_q i - 1..



    if i create dp_p_q cant i merge that with

    also i can merge dp_2 with i - k dp_p_q or dp_q_p


    so when i am at k len window for the first time i have these choices :

        either i make this window % p / % q / % p % q / % q % p.

        when i am move to some next window there i have these options :

            i) that i mod this with p and merge with either i - 1 th % p / % q % p / % p % q..

            ii) that i mod this with q and merge with either i - th % q / % q % p / % p % q

            iii) that i mod this with % p % q and merge with i - th % p % q / % q % p..

            iv) that i mod this with % q % p and merge with i - 1th % p % q / % q % p..



            for % p % q there are more cases :

                we will also need suffixes..


        for % p % q it might be case that :

            % p is extended by i - 1 and % q is extended by i + 1..


        we can do p < q this alone with remove a lot of transitions..

        the transtions after this will become :

        i) arr[i] % q % p

        ii) arr[i] % p

        either i do % q or not..


        if i  apply % q then i will first this window will be prefix of k sized window of % q % p

        and then merge with free state

        how will free state look :

            either i only apply % p or % q % p..

            and merge with best of free state of i - 1..



    there are some positions where % p is good and some positions where % q % p is good..

    now if at some pos i want to apply


    the idea is that once an elements reaches bare min value it cannot be

    changed..

    and we can use that window to keep finding bare minimum by extending that window..











*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p, q;
        cin >> n >> k >> p >> q;
        if (p > q)
            swap(p, q);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> prefix(n, 0), suffix(n, 0), prefix_p(n), prefix_q_p(n);
        for (int i = 0; i < n; i++)
        {
            prefix_p[i] = arr[i] % p;
            prefix_q_p[i] = (arr[i] % q) % p;
            prefix[i] = min(arr[i] % p, (arr[i] % q) % p);
            if (i)
            {
                prefix[i] += prefix[i - 1];
                prefix_p[i] += prefix_p[i - 1];
                prefix_q_p[i] += prefix_q_p[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = min(arr[i] % p, (arr[i] % q) % p);
            if (i < n - 1)
            {
                suffix[i] += suffix[i + 1];
            }
        }
        int res = LLONG_MAX;
        for (int i = k - 1; i < n; i++)
        {
            int first = prefix_p[i];
            int second = prefix_q_p[i];
            if (i - k >= 0)
            {
                first -= prefix_p[i - k];
                second -= prefix_q_p[i - k];
                first += prefix[i - k];
                second += prefix[i - k];
            }
            if (i < n - 1)
            {
                first += suffix[i + 1];
                second += suffix[i + 1];
            }
            res = min({res, first, second});
        }
        cout << res << endl;
    }
    return 0;
}

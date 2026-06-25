#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so s[i] is that whether we remember the value or not..

    and we need to find arr

    and we are also given prefix max from 0...i

    now i am at some index..

    lets say that i have found everything from 0..i - 1

    if i == 0 is  not found then it is literally c[0]

    now for i = 1..n

    i know all the prev values, along with that i will also

    have the prefix sum till i - 1..

    now if c[i] > prefix sum till i - 1..

    then this value should be :  arr[i] = c[i] - prefix_sum..

    else this is some -ve value or maybe 0:

    so no cases are :

        arr[0] is defined and arr[0] != c[0]

        the c array should be non decreasing..


    i will try to fill all the zeroes with 0 only..

    now at some point i will have a value because of which

    i will have to change some prev zero with this.

    now if i dont have zeroes at this point then also false..

    -4,-4,-1,-1
    0,0,0,5
    -4,0,3,5

    so at some point c[i] wont match the prefix till now .

    so i will calc the diff..

    -1,4
    4 + x = -1
    x = c[i] - prefix[i]

    and use some zero to fill this and move on...

    and empty all the zeroes till now..

    and then move on..

    if you dont have enough any zeroes left..

    then gg : false and break..

    1,0,1,1
    2,0,2,5
    2,2,4,11


    2,10,5
    2,2,17


    instead of  filling all the values with some x values  ..

        there are  some pivots..

            we just need to satisfy them using prev zero..

                if i have 1 prev zero i will use that and satisfy this pivot

                    else its not possible..

    WHAT ARE THE PIVOTS :

        c[i] where c[i] > c[i - 1]...

        or where b[i] > c[i]







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
        string s;
        cin >> s;
        vector<int> arr(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        bool ok = 1;
        if ((s[0] == '1') && (arr[0] != c[0]))
        {

            ok = false;
        }
        int temp = c[0];
        for (int i = 0; i < n; i++)
        {
            if (c[i] < temp)
            {
                ok = false;
                break;
            }
            temp = max(temp, c[i]);
        }
        if (ok == false)
        {

            cout << "No" << endl;
            continue;
        }

        int prev_zero = -1;
        arr[0] = c[0];

        int prefix_sum = arr[0];
        int max_seen = arr[0];
        vector<int> prefix(n);
        prefix[0] = arr[0];

        for (int i = 1; i < n; i++)
        {

            if (s[i] == '1')
            {
                prefix_sum += arr[i];
            }
            else
            {
                prev_zero = i;
            }
            prefix[i] = prefix_sum;
            max_seen = max(max_seen, prefix_sum);

            // cout << prefix_sum << ":" << max_seen << ":" << i << endl;
            if (s[i] == '1')
            {

                // i need to clear all the prev things..
                if (max_seen < c[i])
                {
                    // then we need to change things..
                    if (prev_zero == -1)
                    {
                        ok = false;
                        break;
                    }
                    // i will use some zero to make up..
                    int idx = prev_zero;
                    int x = c[i] - prefix[i];
                    if ((prefix[idx] + x) > c[idx])
                    {

                        ok = false;
                        break;
                    }
                    arr[idx] = x;
                    prefix[i] += x;
                    prefix_sum += x;
                    prev_zero = -1;
                }
                else if (max_seen > c[i])
                {
                    if (prev_zero == -1)
                    {
                        ok = false;
                        break;
                    }
                    // i will use some zero to make up..
                    int idx = prev_zero;
                    int x = c[i] - prefix[i];
                    if ((prefix[idx] + x) > c[idx])
                    {

                        ok = false;
                        break;
                    }
                    arr[idx] = x;
                    prefix[i] += x;
                    prefix_sum += x;
                    prev_zero = -1;
                }
            }
            else
            {

                if (max_seen < c[i])
                {
                    int idx = prev_zero;
                    int x = c[i] - prefix[i];
                    if ((prefix[idx] + x) > c[idx])
                    {

                        ok = false;
                        break;
                    }
                    arr[idx] = x;
                    prefix[i] += x;
                    prefix_sum += x;
                    prev_zero = -1;
                }
                else if (max_seen > c[i])
                {
                    // i will use some zero to make up..
                    int idx = prev_zero;
                    int x = c[i] - prefix[i];
                    if ((prefix[idx] + x) > c[idx])
                    {

                        ok = false;
                        break;
                    }
                    arr[idx] = x;
                    prefix[i] += x;
                    prefix_sum += x;
                    prev_zero = -1;
                }
            }

            max_seen = max(max_seen, prefix_sum);
        }
        if (ok == false)
        {
            cout << "No" << endl;
            // for (auto a : arr)
            //     cout << a << ' ';
            // cout << endl;
        }
        else
        {
            cout << "Yes" << endl;
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
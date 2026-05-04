#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    f(a) should be minimized..

    if any single element is div by 6 we

    cant do anything..

    but if its 3,2 we can sep them..

    2 in left end , 3 in right end..

    then some number that is not divisible..

    2,2 on left and then an number that is

    not divisible..

    and on right 3 and then some number not divisible..

    number that i put on left should not have

    factor of 3..

    number that i place on right should not

    have factor of 2..

    first i will try this..

    after i am done doing this..

    on right also i can place 3,3

    and then some number..

    3,3,3 can be plac..

    2,2,2

    can be placed..






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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> six_div;
        vector<int> two_div, three_div, rem;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] % 6) == 0)
            {
                six_div.push_back(arr[i]);
            }
            else if ((arr[i] % 3) == 0)
            {
                three_div.push_back(arr[i]);
            }
            else if ((arr[i] % 2) == 0)
            {
                two_div.push_back(arr[i]);
            }
            else
            {
                rem.push_back(arr[i]);
            }
        }
        vector<int> res(n, -1);
        int left = 0, right = n - 1;
        while (!six_div.empty())
        {
            res[left] = six_div.back();
            six_div.pop_back();
            left++;
        }
        // now 2 and 3 and rem..
        // all 2's from left..
        while (!two_div.empty())
        {
            res[left] = two_div.back();
            two_div.pop_back();
            left++;
        }
        while (!three_div.empty())
        {
            if (res[right] != -1)
                continue;
            res[right] = three_div.back();
            three_div.pop_back();
            right--;
        }
        for (int i = 0; i < n; i++)
        {
            if (res[i] == -1)
            {
                res[i] = rem.back();
                rem.pop_back();
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}

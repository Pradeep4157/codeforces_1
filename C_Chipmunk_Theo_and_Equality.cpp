#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we cant inc even numbers so everything will have to become smallest

    even number..

    or even smaller than smallest even number..

    which even number ?

    from smallest odd also i can just reach odd + 1

    or some smaller number..

    so smallest number in array i take..

    and if its even then make others == this

    or if its odd then either try to make everyone this only(only if all are same.)

    or make everyone == odd + 1..

    its not just min ele..

    when i keep decreasing the elements to make it == min_ele ..

    it might dec by a lot

    like if min ele = 12,

    and 16 when i /= 2 it becomes 8 so i need to make everything == 8..

    now there might be

*/

int find(int x, int min_ele)
{
    int steps = 0;
    while (true)
    {
        if (x <= min_ele)
            break;
        steps++;
        if (x & 1)
            x++;
        else
            x /= 2;
    }
    if ((x == min_ele - 1) && (x & 1))
    {
        x++;
        steps++;
    }
    if (x != min_ele)
        steps = INT_MAX;
    return steps;
}
set<int> find_element(int x)
{
    set<int> st;
    while (true)
    {

        if (x & 1)
            st.insert(x + 1);
        st.insert(x);
        if (x <= 1)
            break;
        if (x & 1)
            x++;
        else
            x /= 2;
    }

    return st;
}
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
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        map<int, int> mp;
        // vector<int> temp = find_element(arr[0]);
        for (int i = 0; i < n; i++)
        {
            set<int> curr = find_element(arr[i]);
            for (auto &a : curr)
            {
                if (i > 0)
                {
                    if (mp.find(a) == mp.end())
                        continue;
                }
                mp[a]++;
            }
        }
        int res = LLONG_MAX;
        for (auto &a : mp)
        {
            // cout << a.first << ":" << a.second << endl;
            if (a.second < n)
                continue;
            int curr = 0;
            for (int i = 0; i < n; i++)
            {
                curr += find(arr[i], a.first);
            }
            res = min(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    when i am at some index i, i just want it to be max..

    so i select some x such that  all the prev's can be >= x

    so i will already have res[i - 1] denoting the max..

    i cant go beyond that..

    if i want some x i will need x - arr[i] from all the prev's

    if that many are there then yes else no..


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
        vector<int> res(n);
        res[0] = arr[0];
        map<int, int> mp;
        int extra = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= res[i - 1])
            {
                res[i] = res[i - 1];
                extra += (arr[i] - res[i - 1]);
                continue;
            }
            int low = arr[i], high = res[i - 1];
            int ans = low;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                int req = mid - arr[i];
                if(req <= extra){
                    ans = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            res[i] = ans;
            mp[res[i]]++;
        }
        for (auto a : res)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}

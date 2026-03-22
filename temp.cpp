#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    of all the subarrays we need second max of them..

    for a left we need to calculate till certain right pointer, after that we can use suffix of that index...

    of an index, we need next 2 bigger elements, till that either this arr[i] will be used / some other ele will be used,

    after that suffix will be same only..

    larg number  in perm will not come in any subarray..

    1 will come only in 1 subarr..






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
            cin >> arr[i];
    }
    return 0;
}

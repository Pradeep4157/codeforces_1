#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if i want to mark  this chair it shouldnt come after

    this

    so if this pi  is <= i then mark else cont..


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
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            curr--;
            if (curr <= i)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}

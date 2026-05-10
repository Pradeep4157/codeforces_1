#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
const int lim = LLONG_MAX;
bool possible(int mid, int k, vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        if (arr[i] >= mid)
            continue;
        int curr = arr[i];
        int diff = mid - curr;
        int req = (diff + i) / (i + 1);
        if (k < req)
            return false;

        k -= req;
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int low = *min_element(arr.begin(), arr.end()), high = LLONG_MAX;
        int res = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid, k, arr))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}

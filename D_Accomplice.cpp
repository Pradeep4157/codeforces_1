#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    its like i select some i and j :

        and the intersection / overlap subarray

        between their time is when the

        crime could have been committed.

    also start + x <= end :

    start....end is the overlap :

    no of ways = end - (start + x) + 1

    firstly we can remove the suspects

    that were not present >= d units

    of time.

    now all we have are valid criminals :

    among all criminals i store their valid prefix[start]++...prefix[end - d + 1]--

    and then i have all the prefixes stored and i just do countC2



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<pair<int, int>> arr(n);
        int m = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            m = max(m, arr[i].second + 10);
        }
        vector<int> prefix(m);
        for (auto a : arr)
        {
            int curr_start = a.first;
            int curr_end = a.second;
            if (curr_end - curr_start < d)
                continue; // this nigga aint criminal..
            int invalid_start = curr_end - d + 1;
            prefix[curr_start]++;
            prefix[invalid_start]--;
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            if (i)
                prefix[i] += prefix[i - 1];
            if (prefix[i] < 2)
                continue;
            // cout << i << " : " << prefix[i] << endl;

            res += ((prefix[i] * (prefix[i] - 1)) / 2);
        }

        cout << res << endl;
    }
    return 0;
}

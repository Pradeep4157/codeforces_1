#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to maximize mex..

    we can only dec the elements

    not increase them..

    we will try to find candidates for each value..

    and we need to mod each with something..

    so they are going to dec...

    i will have to dec each by atleast 1..

    no i can mod with some big value so no dec

    for arr[i]...

    for a value which arr[i] am i going to select..

    i will try to use the smallest elements

    because bigger can be made small

    if some arr[i] > n - 1

    then it is as good as nothing..


    now we have some holes..


    we will try to fill them usin g


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

        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = 0; i < n; i++)
        {

            int req = res;
            if (arr[i] < req)
                continue;

            req = arr[i] - res;
            cout << arr[i] << "::" << req << ":::" << res << endl;
            if ((res == 0) || (arr[i] == res) || (arr[i] % req) != 0)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}

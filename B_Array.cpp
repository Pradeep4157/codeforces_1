#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every i either choose k < arr[i] such that all  arr[j] > arr[i]

    will  get counted..

    else opp..

    also we can take

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
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            int greater = 0, smaller = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                    smaller++;
                else if (arr[i] < arr[j])
                    greater++;
            }
            res[i] = max(smaller, greater);
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}

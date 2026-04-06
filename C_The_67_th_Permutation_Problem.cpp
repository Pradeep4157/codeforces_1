#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:







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
        n *= 3;
        vector<int> arr(n);

        int left = 1, right = n;
        for (int i = 0; i < n; i += 3)
        {
            arr[i] = left++;
            arr[i + 2] = right--;
            arr[i + 1] = right--;
        }

        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    max - min == gcd(arr)

    i am at i,

    if gcd(arr[i],arr[i + 1]) = max - min

    then it is good

    till where is it going to last ?

    either max changes or min changes..

    is it going to last till all the left / right

    elements are within this max and min thing..

    min + gcd = max

    4,6

    it might that if adj are same all the side

    eles should be = either max or min then it is left * right..


        4,6,4,6




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

        int left_end = -1;
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int maxi = max(arr[i], arr[i + 1]);
            int mini = min(arr[i], arr[i + 1]);
            int curr_gcd = __gcd(arr[i], arr[i + 1]);
            if (curr_gcd == maxi - mini)
            {
                int left = 1;
                int right = 1;
                int j = i + 1;
                while (j < n && (arr[j] == maxi || (arr[j] == mini)))
                {
                    j++;
                }
                j--;

                right = j - i;

                j = i;
                while (j > left_end && (arr[j] == maxi || (arr[j] == mini)))
                {
                    j--;
                }
                j++;
                left = i - j + 1;
                left_end = i;

                res += (left * right);
            }
        }
        cout << res << endl;
    }
    return 0;
}

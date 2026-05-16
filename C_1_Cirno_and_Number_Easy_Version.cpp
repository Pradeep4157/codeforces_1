#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    either i make <= a

    or > a

    for <= a i will try to make all the prefix

    same..

    till the point where i cant

    and then i will try to change some prefix

    with some smaller number if i can and if i cant

    then just return LLONG_MAX or change that to biggest

    number < prefix and keep the remaining same..

    and then for current take

    some number


*/
int res, first, n;
vector<int> arr;
int SIZE;

// void recursion(int i, int second)
// {
//     if (i >= SIZE + 1)
//     {

//         res = min(res, abs(first - second));
//         return;
//     }

//     if (i > 0)
//         res = min(res, abs(first - second));
//     int temp = second * 10 + arr[0];
//     recursion(i + 1, temp);
//     if (n > 1)
//     {
//         temp = second * 10;
//         temp += arr[1];
//         recursion(i + 1, temp);
//     }
//     return;
// }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto recursion = [&](auto &&self, int i, long long second) -> void
    {
        if (i >= SIZE + 1)
        {
            res = min(res, abs(first - second));
            return;
        }

        if (i > 0)
            res = min(res, abs(first - second));

        self(self, i + 1, second * 10 + arr[0]);

        if (n > 1)
            self(self, i + 1, second * 10 + arr[1]);
    };
    int t;
    cin >> t;
    while (t--)
    {
        cin >> first >> n;

        string temp = to_string(first);
        SIZE = temp.size();
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        res = LLONG_MAX;
        recursion(recursion, 0, 0);
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
vector<int> arr;
int n;
int recursion(int i, double curr)
{
    if (i == n)
    {
        return 0;
    }
    // either left..
    int res_1 = 0, res_2 = 0;

    double new_curr = curr - (double)arr[i];
    int pos = 0;
    if (new_curr >= 0)
        pos++;
    if (curr >= 0)
    {
        pos++;
    }
    if (pos == 1)
    {
        res_1++;
    }
    res_1 += recursion(i + 1, new_curr);
    new_curr = curr + (double)arr[i];
    pos = 0;
    if (new_curr >= 0)
        pos++;
    if (curr >= 0)
    {
        pos++;
    }
    if (pos == 1)
    {
        res_2++;
    }
    res_2 += recursion(i + 1, new_curr);
    return max(res_1, res_2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.clear();
    arr.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    double curr = 0.5;
    int res = 0;
    cout << recursion(0, 0.5) << endl;

    return 0;
}

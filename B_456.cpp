#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n, m;
double find(int a, int b, int c, vector<vector<int>> &arr)
{
    double first = 0, second = 0, third = 0;
    for (int i = 0; i < n; i++)
    {
        int find = -1;
        if (i == 0)
            find = a;
        else if (i == 1)
            find = b;
        else
            find = c;
        double curr = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == find)
            {
                curr = (curr + (double)(1ll));
            }
        }
        if (i == 0)
            first = curr;
        else if (i == 1)
            second = curr;
        else
            third = curr;
    }
    double res = (first * second * third) / (double(6 * 6 * 6));
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 3;
    m = 6;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    double res = 0;
    res += find(4, 5, 6, arr);
    res += find(4, 6, 5, arr);
    res += find(5, 4, 6, arr);
    res += find(5, 6, 4, arr);
    res += find(6, 5, 4, arr);
    res += find(6, 4, 5, arr);
    cout << res << endl;
    return 0;
}

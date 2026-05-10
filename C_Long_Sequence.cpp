#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i will keep inc size unless size < k

    now the array where i am it is going to get

    added

    how many times i will add that and then rem will give it..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            for (int j = 0; j < m; j++)
            {
                int ele;
                cin >> ele;
                arr[i].push_back(ele);
            }
        }
        vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        int index = 0;
        int size = 0;
        while (index < n)
        {
            int curr = arr[index].size() * c[index];
            if (curr + size >= k)
                break;
            size += curr;
            index++;
        }

        int left = k - size;

        if (left > (arr[index].size()))
        {

            int mul = left / (arr[index].size());
            left -= (mul * arr[index].size());
        }
        left--;
        left += (arr[index].size());
        left %= (arr[index].size());
        cout << (arr[index][left]) << endl;
    }
    return 0;
}

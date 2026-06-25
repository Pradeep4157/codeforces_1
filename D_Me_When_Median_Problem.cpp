#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    the order in which we select the indexes change the final element..

    so we will try to take out the smallest elements first ?

    so i take some smallest element to that element : 3 more are with that..

    i need what is the adj index to the current index..

    once i del some index i adj[i] = adj[i + 1]

    and i + 1 is del..

    but if adj[i + 1] is also deleted i need to keep track of left as well..

    so when i del some index.

    i + 1 index element gets deleted..

    so left of i does not get affected..

    so i need to update adj[i] = adj[i + 1]...

    and then move on..

    and when i take some subarray {i,i + 1}

    i need to  first erase all these 4 elements from set..

    and then add the rem elements to the set..


    but every time we remove some smallest element we also remove some large element and we need that largest element to be as small as possible ??








*/
bool possible(int mid, vector<int> arr, vector<int> b)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mid)
            arr[i] = 0;
        else
            arr[i] = 1;
        if (b[i] < mid)
        {
            b[i] = 0;
        }
        else
            b[i] = 1;
    }
    int cnt_0 = 0, cnt_1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cnt_1++;
        else
            cnt_0++;
        if (b[i] == 1)
            cnt_1++;
        else
            cnt_0++;
    }
    if (mid == 8)
    {
        cout << "ahahah : " << cnt_1 << " : " << cnt_0 << endl;
    }
    return (cnt_1 - cnt_0 >= 0);
}
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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int low = 1, high = 2 * n;
        int res = low;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            cout << mid << endl;
            if (possible(mid, arr, b))
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}

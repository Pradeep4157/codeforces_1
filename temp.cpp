#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
bool possible(int mid, vector<int> &arr, vector<int> &b)
{
    int n = arr.size();
    int curr_time = 0;
    int temp = mid;
    int req = 1;
    for (int i = 0; i < n; i++)
    {

        curr_time += arr[i];
        if (curr_time <= b[i])
            continue;
        else
        {
            curr_time = b[i];
            req++;
        }
    }

    return (mid >= req);
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
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        set<int> st;
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            auto it = st.lower_bound(b[i]);
            if (it == st.end())
            {
                res++;
                st.insert(b[i]);
            }
            else
            {
                st.erase(it);
                st.insert(b[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}

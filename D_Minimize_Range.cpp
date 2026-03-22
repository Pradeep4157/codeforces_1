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
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    set<int> st;
    int maxi = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int dist = maxi - arr[i];
        int curr = dist / k;
        arr[i] += (curr * k);
    }
    for (auto a : arr)
    {
        st.insert(a);
    }
    int res = LLONG_MAX;
    for (int i = 0; i <= n + 100; i++)
    {
        int curr_min = *st.begin();
        int curr_max = *st.rbegin();
        res = min(res, curr_max - curr_min);
        curr_min += k;
        st.erase(st.begin());
        st.insert(curr_min);
    }
    cout << res << endl;

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    once i get the base res..

    the extra thing is same as prev ..

    just instead of adding right - left ..

    i need to add size*(size + 1)/2.

    and size is right - left..



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
        set<vector<int>> st;
        st.insert({0, arr[n - 1], n - 1});
        int res = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            int window_start = -1, window_end = -1, right_end = -1;
            int left = 0;

            for (auto a = st.begin(); a != st.end();)
            {
                auto temp = *a;

                int start = temp[0];
                int end = temp[1];
                int right = temp[2];

                if (end <= arr[i])
                {
                    a = st.erase(a); // move to next

                    temp[2] = i;
                    st.insert(temp);

                    left = end + 1;
                }
                else if (end > arr[i])
                {
                    window_start = start;
                    window_end = end;
                    right_end = right;
                    break;
                }
                else
                {
                    ++a;
                }
            }
            if (window_start == -1)
            {
                if (i == 3)
                    cout << "ehhehe" << endl;
                // this is the biggest found so far..
                // add this window.. this is from left..arr[i] all this is going from i...n - 1
                int cubes = arr[i] - left + 1;
                cubes = max(cubes, 0ll);
                if (cubes > 0)
                {
                    // add this window..
                    st.insert({left, arr[i], n - 1});
                    // add this to res as well..
                    res += (cubes * (n - 1 - i));
                }
            }
            else
            {
                // now there might be some window that is overlapping..
                auto it = st.lower_bound({window_start, window_end, right_end});
                if (it != st.end())
                {
                    vector<int> temp = *it;
                    int temp_1 = temp[0];
                    int temp_2 = temp[1];
                    int temp_3 = temp[2];
                    if (temp_1 == window_start && temp_2 == window_end && temp_3 == right_end)
                    {
                        st.erase(it);
                        // now add the new window..
                        // left is left..
                        // mid is min of window_end and arr[i]
                        int mid = min(window_end, arr[i]);
                        int right = max(window_end, arr[i]);
                        if (mid != right)
                        {
                            st.insert({left, mid, right_end - 1});
                            st.insert({mid + 1, right_end, right_end});
                        }
                    }
                }
            }
            cout << i << ":" << res << endl;
        }
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    123132231

    12212112


    123
    132
    213
    231

    12123

    122331
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
        // if (n == 2)
        // {
        //     vector<int> arr = {1, 2, 2, 1, 2, 1, 1, 2};
        //     for (auto a : arr)
        //         cout << a << " ";
        //     cout << endl;
        //     continue;
        // }
        vector<int> arr(4 * n, -1);
        set<int> indexes;

        int m = arr.size();
        for (int i = 0; i < m; i++)
        {
            indexes.insert(i);
        }
        for (int i = 1; i < n; i++)
        {
            auto it = indexes.begin();
            int idx = *it;
            int curr_idx = idx;
            indexes.erase(it);
            set<int> st = {0};
            arr[idx] = i;
            for (int k = 0; k < 3; k++)
            {
                bool found = false;
                for (int dist = 1; dist < m; dist++)
                {
                    if (!st.count(dist))
                    {
                        // maybe i can use it..
                        // that should not be occupied..
                        if ((curr_idx + dist >= m))
                            continue;

                        if (arr[curr_idx + dist] == -1)
                        {
                            // we can use that..
                            st.insert(dist);
                            arr[curr_idx + dist] = i;
                            curr_idx = curr_idx + dist;
                            indexes.erase(curr_idx);
                            found = 1;
                            break; // because we found..
                        }
                    }
                }
                if (found == false)
                {
                    cout << "CHUD GAYE BHAIYA !!" << endl;
                }
            }
        }
        int last_idx = -1;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] == -1)
            {
                arr[i] = n;
                last_idx = i;
            }
        }
        arr.erase(arr.begin() + last_idx);
        arr.insert(arr.begin(), n);
        for (auto a : arr)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}

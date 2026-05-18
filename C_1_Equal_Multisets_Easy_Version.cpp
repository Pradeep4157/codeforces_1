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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        map<int, int> mp;
        for (auto a : b)
        {
            if (a != -1)
                mp[a]++;
        }

        set<int> st;
        for (int i = 0; i < k; i++)
        {
            st.insert(arr[i]);
        }
        bool ok = 1;
        for (auto a : mp)
        {
            if (a.second > 1)
                ok = false;
        }
        for (int i = n - 1 - k; i >= 0; i--)
        {
            if (b[i] != -1)
            {
                if (b[i] != arr[i])
                {
                    ok = false;
                    break;
                }
            }
        }
        map<int, int> mp_1;
        for (int i = 0; i < n; i++)
        {
            mp_1[arr[i]] = i;
        }
        set<int> first_set, second_set;
        for (int i = n - k; i < n; i++)
        {
            first_set.insert(arr[i]);
        }
        for (int i = n - k; i < n; i++)
        {
            if (b[i] != -1)
            {
                if (i - k + 1 >= 0)
                {
                    int index = mp_1[b[i]];
                    if (index > i)
                    {
                        ok = false;
                        break;
                    }
                }
                if (!first_set.count(b[i]))
                {
                    ok = false;
                    break;
                }
                first_set.erase(b[i]);
            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

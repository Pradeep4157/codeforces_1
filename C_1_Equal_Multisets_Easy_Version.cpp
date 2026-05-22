#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    checking only the last k sized subarray is  not right..

    for all the elements before last k sized subarray :

        arr[i] == b[i] || b[i] == -1

    for the last k elements..

    some elements arr[i] && b[i] can be rearranged..

    but some need to be at i..




*/
bool are_they_equal(vector<int> &arr, vector<int> &b)
{
    int n = arr.size();
    map<int, int> mp;
    for (auto a : arr)
    {
        mp[a]++;
    }
    for (auto a : b)
    {
        if (a == -1)
            continue;
        if (mp.find(a) == mp.end() || (mp[a] <= 0))
        {
            return false;
        }
        mp[a]--;
    }
    return true;
}
bool check_last(vector<int> &arr, vector<int> &b, int k)
{
    map<int, int> mp;
    int n = arr.size();
    for (int i = n - k; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = n - k; i < n; i++)
    {
        if (b[i] != -1)
        {
            if (!mp.count(b[i]) || (mp[b[i]] == 0))
                return false;
            mp[b[i]]--;
        }
    }
    return true;
}
bool check_already(vector<int> &arr, vector<int> &b, set<int> &st, int k)
{
    int n = arr.size();
    map<int, int> mp;
    for (int i = n - k; i < n; i++)
    {
        if (st.count(arr[i]))
        {
            mp[arr[i]] = i;
        }
    }
    for (int i = n - k; i < n; i++)
    {
        if (st.count(b[i]))
        {
            if (b[i] == -1)
                continue;
            int index = mp[b[i]];
            int window_start = index - k + 1;
            window_start = max(window_start, 0ll);
            int window_end = window_start + k - 1;
            window_start = max(window_start, n - k);
            if (i > window_end || i < window_start)
            {
                return false;
            }
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {ff
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ok = are_they_equal(arr, b);
        // now atleast all b's have some ele in a..
        // also apart from the last k window all the other elements should have their partner at i index only..
        for (int i = 0; i < n - k; i++)
        {
            if (b[i] == -1)
                continue;
            if (arr[i] != b[i])
            {
                ok = false;
                break;
            }
        }
        // now checking the final window..
        if (n == k)
        {
            cout << ((ok) ? "YES" : "NO") << endl;
            continue;
        }
        vector<int> dp(n, 0);
        map<int, int> mp;
        for (int i = n - k; i < n; i++)
        {
            mp[arr[i]]++;
        }
        set<int> st;
        for (int i = n - k; i < n; i++)
        {
            if (mp.count(b[i]))
            {
                st.insert(b[i]);
            }
            mp[b[i]]--;
        }
        if (ok == 1)
        {
            ok = check_last(arr, b, k);
        }
        set<pair<int, int>> needed;
        for (int i = n - k; i < n; i++)
        {
            if (st.count(arr[i]))
                continue;
            needed.insert({i, arr[i]});
        }
        map<int, int> MP;
        for (int i = n - k; i < n; i++)
        {
            if (b[i] == -1)
            {
                if (!needed.empty())
                {
                    pair<int, int> first = *needed.begin();
                    needed.erase(needed.begin());
                    int index = first.first;
                    int window_start = index - k + 1;
                    window_start = max(window_start, 0ll);
                    int window_end = window_start + k - 1;
                    window_start = max(window_start, n - k);
                    if (i > window_end || i < window_start)
                    {
                        ok = false;
                        break;
                    }
                    b[i] = first.second;
                }
                else
                {
                    ok = false;
                }
            }
        }
        if (!needed.empty())
        {
            ok = false;
        }
        for (int i = n - k; i < n; i++)
        {
            if (b[i] == -1)
                ok = false;
        }

        // for (auto a : b)
        //     cout << a << ' ';
        // cout << endl;
        // for (int i = n - k; i < n; i++)
        // {
        //     // checking whether this element is valid..
        //     int window_start = i - k + 1;
        //     window_start = max(window_start, 0ll);
        //     int window_end = window_start + k - 1;
        //     // if (window_end >= n - 1)
        //     // {
        //     //     continue;
        //     //     // because we have already proved that there are enough a's in arr for a in b..
        //     // }
        //     // now there might be a chance that a is going to be outside this window ..

        //     window_start = max(window_start, n - k);

        //     bool found = false;
        //     int ones_found = 0;
        //     for (int j = window_start; j <= window_end; j++)
        //     {
        //         if (arr[i] == b[j])
        //         {
        //             found = 1;
        //             break;
        //         }
        //         if (b[j] == -1)
        //         {
        //             if (st.count(arr[i]))
        //                 continue;
        //             // if (dp[j] > 0)
        //             //     continue;
        //             ones_found++;
        //             b[j] = arr[i];
        //             dp[j]++;
        //             break;
        //         }
        //     }

        //     if (found == false)
        //     {
        //         if (st.count(arr[i]))
        //         {

        //             ok = false;
        //             break;
        //         }
        //         if (ones_found == 0)
        //         {

        //             ok = false;
        //             break;
        //         }
        //     }
        // }

        // for (int i = n - k; i < n; i++)
        // {
        //     if (b[i] == -1)
        //     {
        //         if (dp[i] == 0)
        //         {

        //             ok = false;
        //             break;
        //         }
        //     }
        //     // cout << dp[i] << " ";
        // }
        // // cout << endl;
        if (ok)
        {
            ok = check_already(arr, b, st, k);
        }

        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

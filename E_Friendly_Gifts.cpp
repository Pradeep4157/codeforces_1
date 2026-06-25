#include <bits/stdc++.h>

using namespace std;
/*
        OBSERVATIONS:

    5 1  4  1  3  2  4
    0 -4 -1 -4 -2 -3 2

    -3 + 4 = 1


*/

struct Node
{
    int l, r, mn, mx;

    bool operator<(const Node &other) const
    {
        if (l != other.l)
            return l < other.l;
        if (r != other.r)
            return r < other.r;
        if (mn != other.mn)
            return mn < other.mn;
        return mx < other.mx;
    }
};

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
        {
            cin >> arr[i];
        }

        vector<vector<Node>> mp((n + 10) / 2);
        int m = mp.size();

        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int mini = arr[i], maxi = arr[i];

            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                maxi = max(maxi, arr[j]);
                int diff = maxi - mini;
                if (diff + 1 >= m)
                    break;
                if (st.count(arr[j]))
                    break; // because nothing can be done..
                st.insert(arr[j]);
                if ((int)st.size() == (diff + 1))
                {
                    // then all the elements are diff and it is a suitable array..
                    mp[diff + 1].push_back({i, j, mini, maxi});
                }
            }
            st.clear();
        }
        int res = 0;

        bool found = false;
        map<int, pair<int, int>> mp_1;
        for (int i = m - 1; i >= 0; i--)
        {
            if (found)
                break;
            sort(mp[i].begin(), mp[i].end());

            mp_1.clear();
            int curr_size = mp[i].size();

            for (int j = 0; j < curr_size; j++)
            {
                int curr_mini = mp[i][j].mn;
                int curr_start = mp[i][j].l;

                if (mp_1.find(curr_mini) == mp_1.end())
                {
                    mp_1[curr_mini] = {curr_start, curr_start};
                }
                else
                {

                    mp_1[curr_mini].first = min(mp_1[curr_mini].first, curr_start);
                    mp_1[curr_mini].second = max(mp_1[curr_mini].second, curr_start);
                }
            }
            // now each has only 2
            for (auto &a : mp_1)
            {
                int curr_mini = a.first;
                int min_start = a.second.first;
                int min_end = min_start + i - 1;
                int max_start = a.second.second;
                int max_end = max_start + i - 1;
                int next_mini = curr_mini + i;
                if (mp_1.find(next_mini) == mp_1.end())
                    continue;
                int next_min_start = mp_1[next_mini].first;
                int next_min_end = next_min_start + i - 1;
                int next_max_start = mp_1[next_mini].second;
                int next_max_end = next_max_start + i - 1;
                if (min_start > next_min_end || (min_start > next_max_start))
                {
                    res = i;
                    found = 1;
                    break;
                }
                if (min_end < next_min_start || min_end < next_max_start)
                {
                    res = i;
                    found = 1;
                    break;
                }
                if (max_start > next_min_end || max_start > next_max_end)
                {
                    res = i;
                    found = 1;
                    break;
                }
                if (max_end < next_min_start || max_end < next_max_start)
                {
                    res = i;
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        cout << res << endl;
    }

    return 0;
}
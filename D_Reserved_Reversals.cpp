#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    1 4 3 2
    2 3 4 1
    2 3 1 4
    3 2 1 4
    1 2 3 4


*/

struct SegTree
{
    int n;
    vector<int> seg;

    SegTree(vector<int> &a)
    {
        n = a.size();
        seg.resize(4 * n + 10);
        build(1, 0, n - 1, a);
    }

    void build(int idx, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            seg[idx] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * idx, l, mid, a);
        build(2 * idx + 1, mid + 1, r, a);
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
    }

    int query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return INT_MAX;
        if (ql <= l && r <= qr)
            return seg[idx];
        int mid = (l + r) >> 1;
        return min(query(2 * idx, l, mid, ql, qr),
                   query(2 * idx + 1, mid + 1, r, ql, qr));
    }

    void update(int idx, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
    }

    int getMin(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }

    void pointUpdate(int pos, int val)
    {
        update(1, 0, n - 1, pos, val);
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
            cin >> arr[i];
        int min_even = LLONG_MAX, min_odd = LLONG_MAX, max_even = LLONG_MIN, max_odd = LLONG_MIN;
        vector<int> res = arr;
        sort(res.begin(), res.end());
        map<int, vector<int>> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] & 1)
            {
                min_odd = min(min_odd, arr[i]);
                max_odd = max(max_odd, arr[i]);
            }
            else
            {
                min_even = min(min_even, arr[i]);
                max_even = max(max_even, arr[i]);
            }
            mp[res[i]].push_back(i);
        }

        SegTree sg(arr);
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> &indexes = mp[arr[i]];
            int size = indexes.size();
            int min_pos = indexes[size - 1];

            if (min_pos <= i)
                continue;
            int mini = sg.getMin(i, min_pos);
            int odd_count = 0;
            if (mini & 1)
                odd_count++;
            if (arr[i] & 1)
                odd_count++;
            int maxi = arr[i];
            if (odd_count != 1)
            {
                if (odd_count == 0)
                {
                    // both are even .

                    // i can use the odd min number..
                    if ((mini < min_odd) && (maxi > max_odd))
                    {
                        ok = false;
                        break;
                    }
                    else
                        indexes.pop_back();
                }
                else
                {
                    if ((mini < min_even) && (maxi > max_even))
                    {
                        ok = false;
                        break;
                    }
                    else
                        indexes.pop_back();
                }
            }
            else
            {

                indexes.pop_back();
            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

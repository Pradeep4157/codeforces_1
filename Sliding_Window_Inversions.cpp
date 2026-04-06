#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    in this question we can find inversion at all the indexes(if possible..)

    how do we find all the inversions at all the indexes ?

    we can do it with fenwick tree / ordered set ...

    and then we can store the prefix and find the k window thing..

*/
struct BIT
{
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1, 0) {}
    void update(int i, int val)
    {
        for (; i <= n; i += i & -i)
        {
            bit[i] += val;
        }
    }
    int query(int i)
    {
        int res = 0;
        for (; i > 0; i -= i & -i)
        {
            res += bit[i];
        }
        return res;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> compress = arr;
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    int size = compress.size();
    BIT bit(size + 10);
    vector<int> res;
    for (int i = 0; i < k; i++)
    {
        int index = lower_bound(compress.begin(), compress.end(), arr[i]) - compress.begin() + 1;
        bit.update(index, 1);
    }
    int first = k - bit.query(size + 1);
    res.push_back(first);
    for (int i = k; i < n; i++)
    {
        // remove i - k..
        int index = lower_bound(compress.begin(), compress.end(), arr[i - k]) - compress.begin() + 1;
        bit.update(index, -1);
        // now adding arr[i]..
        index = lower_bound(compress.begin(), compress.end(), arr[i]) - compress.begin() + 1;
        bit.update(index, 1);
        res.push_back(k - bit.query(size + 1));
    }
    for (auto a : res)
        cout << a << ' ';
    cout << endl;
    return 0;
}

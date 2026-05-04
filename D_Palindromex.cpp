#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int n;
set<int> st;
bool check_inner(int left, int right, vector<int> &arr)
{
    while (left <= right)
    {
        if (arr[left] != arr[right])
            return false;
        st.insert(arr[left]);
        left++;
        right--;
    }
    return true;
}
void find_outer(int left, int right, vector<int> &arr)
{
    while (left >= 0 && right < n)
    {
        if (arr[left] != arr[right])
            break;
        st.insert(arr[left]);
        left--;
        right++;
    }
}
int center(vector<int> &arr)
{
    int left = -1, right = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (left == -1)
                left = i;
            right = i;
        }
    }
    set<int> st;
    int start = left, end = left;
    while (start >= 0 && end < n)
    {
        if (arr[start] != arr[end])
            break;
        st.insert(arr[start]);
        start--;
        end++;
    }
    int res_1 = 0;
    while (true)
    {
        if (st.count(res_1))
            res_1++;
        else
            break;
    }
    st.clear();
    start = right, end = right;
    while (start >= 0 && end < n)
    {
        if (arr[start] != arr[end])
            break;
        st.insert(arr[start]);
        start--;
        end++;
    }
    int res_2 = 0;
    while (true)
    {
        if (st.count(res_2))
            res_2++;
        else
            break;
    }
    return max(res_1, res_2);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        st.clear();
        n *= 2;
        vector<int> arr(n);
        st.clear();
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int left = -1, right = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                if (left == -1)
                    left = i;
                right = i;
            }
        }
        bool ok = check_inner(left, right, arr);

        int res = 0;
        if (ok)
        {
            find_outer(left, right, arr);
            while (true)
            {
                if (!st.count(res))
                    break;
                res++;
            }
        }
        // one more case that zero is in center..
        res = max(res, center(arr));
        cout << res << endl;
    }
    return 0;
}

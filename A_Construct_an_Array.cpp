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
        set<int> st;
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
        {
            st.insert(i);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            int first = *st.begin();
            st.erase(st.begin());
            res[i] = first;
            if (i)
            {
                st.erase(first + res[i - 1]);
            }
        }
        for (auto a : res)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}

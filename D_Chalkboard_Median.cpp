#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int q;
        cin >> q;
        int x;
        cin >> x;
        ordered_set<int> st;
        st.insert(x);
        while (q--)

            int a, b;
        cin >> a >> b;
        st.insert(a);
        st.insert(b);
        int size = st.size();
        int mid = size / 2;
        cout << (*st.find_by_order(mid)) << endl;
    }
    return 0;
}

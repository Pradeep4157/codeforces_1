#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    at max we are going to add 1e5 trees



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> ms;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int height;
            cin >> height;
            ms.insert(height);
        }
        else
        {
            int height;
            cin >> height;
            while (true)
            {
                if (ms.empty())
                    break;
                auto it = ms.begin();

                int ele = *it;
                if (ele <= height)
                {
                    ms.erase(ms.begin());
                }
                else
                    break;
            }
        }
        cout << ms.size() << endl;
    }
    return 0;
}

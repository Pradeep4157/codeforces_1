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
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto a : s)
        {
            mp[a]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto a : mp)
        {
            pq.push({a.second, (a.first - 'a')});
        }
        int n = s.size();
        vector<int> res(n, -1);
        bool ok = 1;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> top = pq.top();
            pq.pop();
            if (i)
            {

                if (res[i - 1] == top.second)
                {

                    if (pq.empty())
                    {

                        ok = false;
                        break;
                    }
                    pair<int, int> top_2 = pq.top();
                    pq.pop();
                    if (top_2.first == 0)
                    {

                        ok = false;
                        break;
                    }
                    res[i] = top_2.second;
                    top_2.first--;
                    pq.push(top);
                    if (top_2.first > 0)
                    {
                        pq.push(top_2);
                    }
                }
                else
                {
                    res[i] = top.second;
                    top.first--;
                    if (top.first > 0)
                    {
                        pq.push(top);
                    }
                }
            }
            else
            {
                res[i] = top.second;
                top.first--;
                if (top.first > 0)
                    pq.push(top);
            }
        }
        if (ok == false)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
            for (auto a : res)
            {
                char c = a + 'a';
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}

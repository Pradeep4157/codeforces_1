#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    (((())
    ()()))


    123432
    1010-1-2

    it should never go neg..

    so at any point if anything is

    going neg..

    i will take open from other

    if it has

    and add it here

    else ok = false and break..






*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int first = 0, second = 0;
        bool ok = false;
        for (auto a : s)
        {
            if (a == '(')
                first++;
            else
                first--;
        }
        for (auto a : t)
        {
            if (a == '(')
                second++;
            else
                second--;
        }
        if (first + second != 0)
        {

            cout << "NO" << endl;
            continue;
        }
        ok = 1;
        first = 0, second = 0;
        vector<int> swap_a, swap_b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                first++;
            else
                first--;
            if (t[i] == '(')
                second++;
            else
                second--;
            if (s[i] == '(' && t[i] == ')')
            {
                swap_b.push_back(i);
            }
            if (s[i] == ')' && t[i] == '(')
            {
                swap_a.push_back(i);
            }
            if (first < 0)
            {
                // i need to swap some prev ) with (
                if (swap_a.empty())
                {
                    ok = false;
                    break;
                }
                while (first < 0)
                {
                    if (swap_a.empty())
                        break;
                    swap_a.pop_back();
                    first += 2;
                    second -= 2;
                }
                if (first < 0)
                {
                    ok = 0;
                    break;
                }
            }
            if (second < 0)
            {

                if (swap_b.empty())
                {

                    ok = 0;
                    break;
                }
                while (second < 0)
                {

                    if (swap_b.empty())
                        break;
                    swap_b.pop_back();
                    second += 2;
                    first -= 2;
                }
                if (second < 0)
                {
                    ok = false;
                    break;
                }
            }
            if (first < 0 || second < 0)
            {
                ok = 0;
                break;
            }
        }

        cout << ((ok) ? "YES" : "NO") << endl;

        // atleast they can exchange..
    }
    return 0;
}

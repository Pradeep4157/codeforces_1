#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can do it at most once..

    so string will be atl..

    and then at some index we will


    get index

    same from right side

    and then we will reverse this part


    and if satisfies then yes else no..




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
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < n - 1)
        {
            if (s[left] == s[left + 1])
                break;
            left++;
        }
        right = left + 1;
        while (right < n - 1)
        {
            if (s[right] == s[right + 1])
                break;
            right++;
        }

        if (left != n - 1 && (left <= right))
        {
            for (int i = left + 1; i <= right; i++)
            {
                s[i] = ((s[i] == 'b') ? 'a' : 'b');
            }
        }

        bool ok = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}

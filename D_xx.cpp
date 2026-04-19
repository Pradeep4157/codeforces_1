#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    first the no of x's should  be same in both

    the strings..

    all the 2 x substrings that are covered with

    brackets we will remvoe from both a and b

    and after this is both of them are

    same then yes else no..

    how we will rem optimally..


    first i need to find (xx) this substring..

    then using left and right i keep doing

    is_there[left],right = false..

    keep going unless they are same.. & is_there is also true..


    then move to right + 1 ..



*/
bool find(int i, string &s)
{
    return ((s[i] == '(') && (s[i + 1] == 'x') && (s[i + 2] == 'x') && (s[i + 3] == ')'));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size();
        int m = b.size();
        vector<bool> is_there_1(n, 1), is_there_2(m, 1);
        int right = 0;
        while (right + 3 < n)
        {
            bool is_it = find(right, a);
            if (is_it)
            {
                int start = right;
                int end = right + 3;
                while (start >= 0 && end < n)
                {
                    // while (start >= 0 && a[start] == 'x')
                    //     start--;
                    // while (end < n && a[end] == 'x')
                    //     end++;
                    if (is_there_1[start] == false || is_there_1[end] == false || (a[start] != '(') || (a[end] != ')'))
                        break;
                    is_there_1[start] = false;
                    is_there_1[end] = false;
                    start--;
                    end++;
                }
                right = end;
            }
            else
                right++;
        }
        right = 0;
        while (right + 3 < m)
        {
            bool is_it = find(right, b);
            if (is_it)
            {
                int start = right;
                int end = right + 3;
                while (start >= 0 && end < m)
                {
                    // while (start >= 0 && b[start] == 'x')
                    //     start--;
                    // while (start < m && b[end] == 'x')
                    //     end++;
                    if (is_there_2[start] == false || is_there_2[end] == false || (b[start] != '(') || (b[end] != ')'))
                        break;
                    is_there_2[start] = false;
                    is_there_2[end] = false;
                    start--;
                    end++;
                }
                right = end;
            }
            else
                right++;
        }
        string res_1, res_2;

        for (int i = 0; i < n; i++)
        {
            if (is_there_1[i])
                res_1 += a[i];
        }
        for (int i = 0; i < m; i++)
        {
            if (is_there_2[i])
                res_2 += b[i];
        }

        // cout << res_1 << ":" << res_2 << endl;
        bool ok = (res_1 == res_2);

        cout << ((ok) ? "Yes" : "No") << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    (m + 2*x)%3 == 0




*/
int n;
pair<int, int> find(int x, int y)
{
    while (true)
    {

        if ((x <= n) && (y <= n))
            break;
        y = ((3 * x) - y);
        if (y & 1)
        {
            x = -1, y = -1;
            break;
        }
        y /= 2;
        swap(x, y);
        if (x == y)
        {
            x = -1, y = -1;
            break;
        }
    }
    return {x, y};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        bool ok = false;
        int first = -1, second = -1;
        if (n >= m)
        {
            int first = m;
            int second = m - 1;
            if (second == 0)
                second = first + 1;
            if (first > second)
                swap(first, second);
            cout << first << " " << second << endl;
            continue;
        }

        for (int x = 1; x <= min(m - 1, 1000000ll); x++)
        {

            int left = x * 2ll;
            left += m;
            if (left % 3)
                continue;
            int y = left / 3ll;
            pair<int, int> final = find(x, y);
            int temp_y = y;
            int X = final.first;
            y = final.second;
            // if (X == 6 && y == 5)
            // {
            //     cout << x << ":" << temp_y << endl;
            // }
            if ((X > 0) && (X <= n) && (y > 0) && (y <= n))
            {

                ok = 1;
                first = X;
                second = y;
                break;
            }
        }
        if (ok)
        {
            cout << first << " " << second << endl;
        }
        else
            cout << first << endl;
    }
    return 0;
}

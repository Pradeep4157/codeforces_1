#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    first count the no of zeroes..

    then i will have the no of people that can sit..

    if both the adj values are > arr[i] then there's no way arr[i] is sitting..

    2111111111111

    this can be done using prefix / suffix...

    0 case is done..

    now for possible sc

    -1 = 0
    0 = 2
    1 = 4

    1,2,3,4
    012301
    011_01
    SUUUSU

    WHAT IS THE UPPER BOUND OF THE DEMAND THAT ARR[I]  CAN PLACE = NUMBER OF PEOPLE

    THAT SAT AT TIME ARR[I] - 1

    WHAT IS THE LOWER BOUND :

        IT DEPENDS ON 2 THINGS :

            I) ARR[I] - 1 WHAT IS THE LOWER BOUND

            II) WHAT IS MIN ADJ TIME AT WHICH IT SAT..

        IF ADJ MIN < ARR[I] - 1 THEN I CANT USE LOWER BOUND OF TIME ARR[I] - 1

        BECAUSE IF I USE THEN I SHOULD HAVE SAT AT TIME ARR[I] - 1

        IF ADJ MIN IS ARR[I] - 1 THEN I CAN USE LOWER BOUND OF ARR[I] - 1 BECAUSE I WILL BE LIKE

        ADJ MIN HAS  NOT SAT YET...

    affecting factors are :

        fastest nei that sits..

    BUT ITS NOT SOME GLOBAL THING

    I WILL HAVE TO TRAVERSE LIKE 0'S AND THEN IF ADJ IS 1 THEN GO ON

    PUSH THEM LIKE THAT

    AND AT THE END ANS IS MUL OF WHOLE DP ARRAY IF SOME ELE IS TRAVERSED THEN THE WHOLE ANS

    WILL BY DEF BECOME 0..

    IF MIN ADJ >= ARR[I] - 1 THEN I CAN GO FROM 1...UPPER..

    ELSE


*/
const int mod = 676767677;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> dp(n, 0);
        int already = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                q.push({0, i});
            }
        }
        map<int, int> mp;
        vector<bool> vis(n, false);
        vector<int> upper(n), lower(n);
        while (!q.empty())
        {
            pair<int, int> top = q.top();
            int front = top.second;
            q.pop();
            if (vis[front])
                continue;
            vis[front] = 1;
            if (arr[front] == 0)
            {
                dp[front] = 1;
                upper[front] = 1;
                lower[front] = 1;
            }
            else
            {

                int ele = arr[front];
                int maxi = mp[ele - 1];
                int adj_mini = INT_MAX;
                int adj_upper = INT_MIN;
                int mini;
                int adj_lower = INT_MAX;
                if (front - 1 >= 0)
                    adj_mini = arr[front - 1];
                if (front + 1 < n)
                    adj_mini = min(adj_mini, arr[front + 1]);
                if (adj_mini < ele - 1)
                {
                    mini = maxi;
                    if (ele - 2 >= 0)
                    {
                        int people_sat = mp[ele - 2];
                        mini = people_sat + 1;
                    }
                }
                else
                {
                    mini = 1;
                }
                dp[front] = maxi - mini + 1;
                upper[front] = maxi;
                lower[front] = mini;
            }
            already++;
            mp[arr[front]] = already;

            if (front - 1 >= 0)
            {
                if (arr[front - 1] > arr[front])
                {
                    if (vis[front - 1] == 0)
                        q.push({arr[front - 1], front - 1});
                }
            }
            if (front + 1 < n)
            {
                if (arr[front + 1] > arr[front])
                {
                    if (vis[front + 1] == false)
                        q.push({arr[front + 1], front + 1});
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << lower[i] << ":" << upper[i] << endl;
        // }
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            res *= dp[i];
            res %= mod;
        }
        // for (auto a : dp)
        //     cout << a << ' ';
        // cout << endl;
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so when we exploring all the paths that current unexplored can offer..

    what it gives is not only current path but it gives us no of paths in the suffix of this path..


    we start from 1 now we go to 2,3,4,.....

    if this is unexplored then keep exploring..

    else :

        we know how many suffixes is it present so just do k += dp[i]

    so once a nodes suffix is stored in dp it should be again done in some other node's searching..


    so index is not an invarient, size is also not an invarient..

    WHY ?

    size : because there can be multiple subtrees

    so each start from 1..x and then 1...y

    we can do like this :

    so size keeps increasing ..

    and then at a point it will decrease / equal to prev

    that is indication that prev one was full path or full subtree..

    so we take that

        and in that we take

        subtree and in subtree and fill the dp array with all those values..








*/
vector<int> find(int k)
{
    cout << "? " << k << endl;
    int q;
    cin >> q;
    vector<int> res;
    if (q == 0)
        return res;
    for (int i = 0; i < q; i++)
    {
        int ele;
        cin >> ele;
        res.push_back(ele);
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        set<pair<int, int>> edges;
        vector<pair<int, int>> dp(n + 1, pair<int, int>(-1, 0));
        int k = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i].first != -1)
            {
                k += dp[i].second;
            }
            else
            {
                // this is unexplored..
                vector<int> prev = {} while (true)
                {
                    vector<int> curr = find(k);
                    int curr_size = curr.size();
                    int prev_size = prev.size();
                    if (curr_size > prev_size)
                    {
                        // the subtree is continuing..
                        prev = curr;
                        k++;
                        continue;
                    }
                    // else now it has started new subtree of new node or this node only..
                    // so we take all the info from prev..
                    for (int j = 0; j < prev_size; j++)
                    {
                        if (j < prev_size - 1)
                        {
                            edges.insert({prev[j], prev[j + 1]});
                        }
                        int curr = prev[j];
                        if (dp[curr].second == 0)
                        {
                            // no
                        }
                    }
                }
            }
        }
        // for (auto a : dp)
        // {
        //     cout << a.first << ":" << a.second << endl;
        // }
        m = edges.size();
        cout << "! " << m << endl;
        for (auto a : edges)
        {
            cout << a.first << " " << a.second << endl;
        }
    }
    return 0;
}

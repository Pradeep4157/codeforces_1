#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    ((#()#
    (#)())


    (()())

    ##)())





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> res(n, 0);
        deque<int> open_indexes;
        vector<int> suffix(n, 0);
        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                sum++;
            }
            suffix[i] = sum;
        }
        vector<int> open_dp(n, 0);
        vector<set<int>> close_dp(n);
        sum = 0;
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                temp.push_back(i);
            else
            {

                for (auto a : temp)
                {
                    close_dp[i].insert(a);
                }
                if (!temp.empty())
                {
                    temp.pop_back();
                }
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                sum++;
            }
            else
            {

                open_dp[i] = sum;
                if (sum > 0)
                    sum--;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (s[i] == '(')
        //         cout << open_dp[i] << " ";
        //     // else
        //     //     cout << close_dp[i] << " ";
        // }
        // cout << endl;
        int open_creeps = 0;
        int close_creeps = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                open_indexes.push_back(i);
                close_creeps += open_dp[i];
            }
            else
            {
                open_creeps += close_dp[i].size();
                // here we decide..
                if (k > 0)
                {
                    // we will try to save the minimum one..
                    // because we can pop either closest open or this one but whoeever has lesser population we will remove that..
                    if (open_indexes.empty())
                    {
                        // then we dont need to do anything..
                        continue;
                    }
                    else
                    {

                        // cout << i << " : " << open_creeps << " : " << close_creeps << endl;
                        if (open_creeps >= close_creeps)
                        {
                            // then  it is better close this index..
                            k--;

                            res[i] = 1;
                            open_creeps -= open_indexes.size(); // because all those open brackets were about to pair with this close bracket..
                            // this bracket was related to recent most open_index..
                            int idx = open_indexes.back();
                            for (int j = i + 1; j < n; j++)
                            {
                                if (s[j] == ')')
                                {
                                    if (!close_dp[j].count(idx))
                                    {
                                        close_dp[j].insert(idx);
                                    }
                                }
                            }
                        }
                        else
                        {
                            // it is better to remove all these open brackets..
                            while (k > 0 && (!open_indexes.empty()))
                            {
                                res[open_indexes.front()] = 1;
                                k--;
                                int idx = open_indexes.front();
                                //  first remove all the open braccket creeps from
                                close_creeps -= open_indexes.size();
                                for (int j = idx + 1; j < n; j++)
                                {
                                    if (close_dp[j].count(idx))
                                    {
                                        close_dp[j].erase(idx);
                                    }
                                }
                                open_indexes.pop_back();
                            }
                        }
                    }
                }
                else
                {
                    // if we dont have any k left then what can we do.. nothing...
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     if (res[i] == 0)
        //     {
        //         cout << s[i] << " ";
        //     }
        // }
        // cout << endl;
        for (auto a : res)
            cout << a;
        cout << endl;
    }
    return 0;
}

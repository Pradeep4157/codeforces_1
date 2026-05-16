#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    first we can check the first k length window..

if something in a is no there in b that can be compensated using -1 (sometimes, not always)

but if there is something in b that is not present in a then its just false..

first we store all the values of a in some map and then for each value of b we check

whether it is present in a or not if not then gg => ok = false; break;

now if we are safe after this that means the window is same.. because whatever's remaining

is just some values in a and some -1's in b..

now we change these -1's to the values of a on the basis of increasing indexes..

i.e., first -1 -> first value in a which has no value in b..

now values are assigned and window is perfect..

now we move ahead..


there isn't much change apart from 2 values get removed from left and 2 values are added from

right..

now if the values that get removed from left are same then the values that are added from right

should also be same..

if the values that get removed from left are different.

that means a has some value x that needs in b and b has some value y that should be in a..

so if a[new_index] != b[removed_index] || a[removed_index] != b[new_index] then we are cooked

that is ok = false; break;

else assign the values if b is -1


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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool ok = 1;
        // first window check..
        map<int, vector<int>> mp;
        for (int i = 0; i < k; i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int> indexes;
        for (int i = 0; i < k; i++)
        {
            if (b[i] == -1)
            {
                indexes.push_back(i);
                continue;
            }
            if (mp.find(b[i]) == mp.end())
            {
                ok = false;
                break;
            }
            if (mp[b[i]].empty())
            {
                ok = false;
                break;
            }
            mp[b[i]].pop_back();
            if (mp[b[i]].size() == 0)
            {
                mp.erase(b[i]);
            }
        }

        if (ok == false)
        {
            cout << "NO" << endl;
            continue;
        }
        int z = 0;
        vector<int> first_indexes;
        for (auto a : mp)
        {
            if (a.second.size() > 0)
            {
                int val = a.first;
                vector<int> curr_indexes = a.second;
                for (auto c : curr_indexes)
                {
                    first_indexes.push_back(c);
                }
            }
        }
        sort(first_indexes.begin(), first_indexes.end());
        for (auto a : first_indexes)
        {
            b[indexes[z++]] = arr[a];
        }
        for (int i = k; i < n; i++)
        {
            // left removal..
            int left = i - k;
            if (arr[left] != b[left])
            {
                if (arr[i] != arr[left])
                {
                    ok = false;
                    break;
                }
                if ((b[i] != -1) && (b[i] != b[left]))
                {
                    ok = false;
                    break;
                }
                if (b[i] == -1)
                {
                    b[i] = b[left];
                }
            }
            else
            {
                // now same things are removed , now same things should be added..
                if ((b[i] != -1) && (arr[i] != b[i]))
                {
                    ok = false;
                    break;
                }
                if (b[i] == -1)
                    b[i] = arr[i];
            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

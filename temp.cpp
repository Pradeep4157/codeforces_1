#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i can think in 2 directions :

        either i decide what value should i make of arr[i]..

        or i decide what value should i add to this arr[i]..

        i should also keep track of what i add prev..

        WHAT ARE THE BOUNDS :

            i) values of arr[i] are going to be from 0..k - 1

            ii) subarrays can be from 1..n

        i greedily try to make this ele as small as i can

        from 0...k - 1

        to achieve this value x :

            if x is greater i will have to add x - arr[i] or 2 * (x - arr[i]) or 3 * (x - arr[i])..

            whatever values present..

            also if prev addition allows then will do that..

            so end of this loop is going to be 0...(arr[i] + prev) % k


            if zero then try something..

            but this is also structurally not correct because i am not considering

            completing all the subarrays from 1..max that i used..


    i will have to keep track of no of same subarrays that i can make

    as well..

    if there are 2 choices :

        i) merge with prev idx.

        ii) choose some x subarray both give same res..

        which one should i choose ?

        -> if x <= max choosen so far then yes ?

        -> if x > max then try to merge because that just increases the no of subarrays

        that we need to make ?

        i will also need the track of lines i have added so far...


    k = 5, arr[i] = 3 i want to make it 4..

    i can add 1,6,10,



*/
bool find(int left, int subarays_to_make)
{
    // since i am cutting at i - 1 so.
    subarrays_to_make--;
    // also i cant cut after n - 1..
    left--;
    return (left >= subarays_to_make);
}
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int max_sub = 1;
        int partitions = 0;
        int prev = -1;
        vector<int> res;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < k; j++)
                {
                    // is this one possible..
                    if (j >= arr[i])
                    {
                        // we can try to just add
                        int diff = j - arr[i];
                        if (st.count(diff))
                        {
                            // we can make >= diff subarrays or not we will have to check..
                            bool possi_check = find(n - i, max(max_sub, diff + 1) - partitions);
                            if (possi_check)
                            {
                                res[i] = j;
                                st.erase(diff);
                                partitions++;
                                max_sub = max(max_sub, diff + 1);
                                break;
                            }
                        }
                    }
                    // the flow of j < arr[i] and j >= arr[i] has only 1 diff step..
                }
            }
            // zero is processed in a diff way so that we keep track of pos left with making paritions at i - 1 gap.
        }
    }
    return 0;
}

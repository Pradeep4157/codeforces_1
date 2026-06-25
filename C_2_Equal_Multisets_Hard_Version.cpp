#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    in v1 since there were only 1 occurence of each ele in arr so they needed to  be 1 : 1

    lets say that b[i] was earlier paired with arr[j]

    and j <= i,  now we need to find some k from j + 1..j + k - 1 that is == b[i]...

    we will greedily take the smallest cause that's all that we can do ..

    or the structure is something else..

    its wrong because first array values are also dependent :

    so we store all the unique values's indexes except -1..

    and then we keep iterating and pairing..

    now when i am checking for some index..

    now i will have to store them on the basis of pair where second will tell me whether it is from first / second array..

    if currently i am processing first array index then i can use some -1 ..

    else i cannot..

    what's the starting index of -1 that i find


    the structure is just handling the transition from l,r -> l + 1,r + 1..

    what happens :

        lets say that everything was fine till l,r now

        we lose al,bl and we gain ar,br..

        what are the cases :

            al == bl then we might assume that next new element should also be ar == br

            this might not be true though..

            because this means that al was in 1 : 1 relationship with bl but that might not

            be true

            an al would be connected to some other idx > l && idx < r

            but that also means that bl also was connected to some idx_2 > l && idx_2 < r

            now if both these statements are true then those 2 can connect with each other..

            Hence proved : that if al == bl we just need to ensure that ar == br..

            so if al == bl and ar == br or al == ar && bl == br then we can continue..

            if al != ar its not possible..

            now bl != br..

            if br == -1  we can continue..

            if bl == -1 it might be true or might be false...

            else false and break...

            now only case left is bl == -1..

            it is connected to some ele :

                how to know which ele is it connected to..

                for this we can have a multiset of values that are connected to - 1....

            if this b[r] is in the multiset then pop that element and cotinue..



            now :

            al != bl..

                here the base case should be that al == ar..

                and then if br is -1 then we can continue..

                now the main thing is bl :

                    if that is -1 then we are good..



            so what happens :

                there was some b[idx] which was connected to al and this new element should be ar == al..

                also there was some a[idx] that was connected to b[l] now same thing..

                so a[l] == a[r]

                and b[l] == b[r] or b[r] == -1..


                -1 2
                2 -1
                2 3








*/
pair<bool, vector<int>> is_first_valid(vector<int> &first, vector<int> &second, int k)
{
    int n = first.size();
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        mp[first[i]]++;
    }
    for (int i = 0; i < k; i++)
    {
        if (second[i] == -1)
            continue;
        if ((mp.find(second[i]) == mp.end()) || mp[second[i]] == 0)
            return {false, {}};
        mp[second[i]]--;
    }
    vector<int> res;
    for (auto a : mp)
    {
        while (a.second > 0)
        {
            a.second--;
            res.push_back(a.first);
        }
    }
    return {true, res};
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

        vector<int> first(n), second(n);
        for (int i = 0; i < n; i++)
            cin >> first[i];
        for (int i = 0; i < n; i++)
            cin >> second[i];

        bool ok = 1;
        if (k == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (second[i] == -1)
                    continue;
                else
                {
                    if (second[i] != first[i])
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok == false)
            {
                cout << "NO" << endl;
                continue;
            }
            else
            {
                cout << "YES" << endl;
                continue;
            }
        }

        pair<bool, vector<int>> first_res = is_first_valid(first, second, k);
        if (first_res.first == false)
        {
            ok = false;
            cout << "NO" << endl;
            continue;
        }
        multiset<int> ms;
        for (auto a : first_res.second)
        {
            ms.insert(a);
        }
        for (int i = k; i < n; i++)
        {
            int left = i - k;
            int right = i;
            if ((first[left] == second[left]) && (first[right] == first[right]))
                continue;
            if ((first[left] == first[right]) && (second[left] == second[right]))
                continue;
            if(second[left] == -1){
                // first[left] was connected to this.. or it was conected to someone else..
                if(ms.count(first[left])){
                    // now second[right] should satisfy with first[right]..
                    auto it = ms.lower_bound(first[left]);
                    if(it != ms.end()){
                        ms.erase(it);
                    }
                    if(second[right] == first[right]){
                        continue;
                    }
                    else if(second[right] == -1){
                        ms.insert(first[right]);
                        continue;
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
                else{
                    // -1 was connected to someone else now that nigga should be connected to second[right]..
                    if(first[left] != first[right]){
                        ok = false;
                        break;
                    }
                    if(second[right] == -1){
                        continue;
                    }
                    if(!ms.count(second[right])){
                        ok = false;
                        break;
                    }
                    else{
                        auto it = ms.lower_bound(second[right]);
                        if(it != ms.end()){
                            ms.erase(it);
                        }
                    }
                }
            }
            else{
                if(first[left] == second[left]){
                    // first right should be connected to second[right]..
                    if(second[right] == -1){
                        ms.insert(first[right]);
                        continue;
                    }
                    else if(second[right] == first[right]) continue;
                    else{
                        ok = false;
                        break;
                    }
                    
                }
                else{
                    if(ms.count(first[left])){
                        auto it = ms.lower_bound(first[left]);
                        ms.erase(it);
                        ms.insert(first[right]);
                        
                    }
                    else{
                        ok = false;
                        break;
                    }
                }

            }
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}

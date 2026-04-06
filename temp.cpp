#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every y we can bs..


    now x and y both vary..

    we cant even precomp because y vary..

    so before processing all these queries

    i think that if this is the end what worst

    is it giving me ?


    if y is too large wouldnt the window be

    really small because of a lot of left values

    incapable ?


    if y is small then window is big but for that thing

    the window size will be really small ?

    so what if we precomp values for these small sums

    and brute force for large sums ?


    so we store sums till root n ?

    but does it have any relation with the size of array ?

    no we will store till root sum of array ..

    and if y > root sum of array, then  we will

    find that manually..

    should we precomp till root of sum

    or root of max y..

    we will try both..



    if y is 1e9 precomp will go till 1e9

    so better if we use sum sqrt..






*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        prefix[i] = sum;
    }
    int lim = sqrt(sum);
    vector<vector<int>> dp(n, vector<int>(lim + 1, 0));
    for (int i = 0; i < n; i++)
    {
        int curr_lim = min(lim, prefix[i]);
        for (int j = 1; j <= curr_lim; j++)
        {
            auto it = lower_bound(prefix.begin(),prefix.end(),prefix[i] - j);
            int index = it - prefix.begin();
            dp[i][j] = i - index + 1;
            if(i) dp[i][j] = max(dp[i][j],dp[i - 1][j]);
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    when i remove the top

    of some col..

    then all the cells to the  left

    of it that are connected to it

    will only get affected..

    given that this was not moving..

    so if there is such a col..

    so there will be series of col..

    i will try to

    remove a col top "ONLY" when all

    the cells on right till n - 1..

    are not moving..

    that is there is no hole on right of

    this cell..

    and once i do this ..

    the subarray from this to whatever connected

    is going to move

    and i will get that cost..

    so i need some sort of prefix and suffix..

    suffix will tell me the no of cols

    that are on right of this and arent moving..

    if they are

    intially i will have some default res...

    to that i will try to inc it..

    so i am at some tower top if the suffix thing of this reaches n - 1..

    then it is beneficial to remove this and shift count inc by prefix[i - 1]...

    else no point as nothing's gonna change..

    now i need to find 3 things :

    how will i find the default shifts..

    how will i find prefix and suffix..

    for  default shifts..

    i need next greater tower..

    i just need to find the no of cubes that are moving

    at n - 1 i will have height that height is going to be height that doesnt move

    now at every i -> n - 2 .... 0

    height above curr height will move

    and below wont..

    now this is base res..

    now i try to inc this base res..

    so some height is not moving..

    i.e., curr height >= height of this tower..

    so i will remove top and prefix will move..

    also prefix is going to be if height[i - 1] >= height[i] then prefix[i] += prefix[i - 1] + 1 else 0..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 0;
        int base_height = arr[n - 1];
        vector<int> dp(n);
        dp[n - 1] = base_height;
        for (int i = n - 2; i >= 0; i--)
        {
            int curr = arr[i] - base_height;

            curr = max(curr, 0ll);
            res += curr;
            dp[i] = base_height;
            base_height = min(base_height, arr[i]);
        }
        vector<int> prefix(n);
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] >= arr[i])
            {
                prefix[i] += prefix[i - 1] + 1;
            }
            else
                prefix[i] = 1;
        }
        int right = n - 1;
        int ans = res;
        while (right >= 0)
        {
            // i will remove top of this..
            int left = right - 1;
            while (left >= 0 && (arr[left] >= arr[right]))
                left--;
            left++;
            // now tops from left...right will move..
            int curr = right - left;
            res = max(res, ans + curr);
            right = left - 1;
        }

        cout << res << endl;
    }
    return 0;
}

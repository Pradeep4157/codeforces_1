#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    using BS we will first find the left end and then right end

    and then for the middle thing ..

    the window is from left + 1..right - 1

    now if i check for left + 1...right

    if size if the size of window..

    then x = no of single.

    size - x = rem

    in this rem there are y 2's and 1 three

    so (rem - 3 ) / 2 no of 2's

    for a mid i will see the no of >= 2's from left..mid

    and then no of >= 2's after removing the left pointer.

    if both of them are diff then that middle element was somewhere from left..mid but because i removed mid

    it also got removed..

    else it is somewhere on the right side..

    now from left..mid it can be this point only

    2323

    to check if this one is the mid from mid...right there would be some no of >= 2

    and when i remove the right if that also dec..

    that means the mid is also present from mid...right

    so there is interesction and only 1 point in common that is this point so this is the mid...

    now how do i find the left and right points..

    for left point right will be const at n - 1..

    now left is going to be from 0...n - 2

    so for every mid i will check :

        from mid..n - 1

        i will get some x no of ones and if i sub that from size i should still be getting odd len left..

        because size - x  =  3 + 2*y

        so if its still odd then left is somewhere from mid...right

        else mid is somewhere from left...mid - 1


    same for right point as well...

*/
bool query_1(int left, int right)
{
    int k = right - left + 1;
    cout << "? " << k << " ";
    for (int i = left; i <= right; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    int ones;
    cin >> ones;
    int rem = k - ones;
    return (rem & 1);
}
bool query_2(int left, int right)
{
    // here we check 1st from left..right && then  from left + 1..right, if no of ones inc.. then yes it is here only..
    int k = right - left + 1;
    cout << "? " << k << " ";
    for (int i = left; i <= right; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    int ones_first, ones_second;
    cin >> ones_first;
    cout << "? " << k - 1 << " ";
    for (int i = left + 1; i <= right; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    cin >> ones_second;
    return (ones_second > ones_first);
}
bool query_3(int left, int right)
{
    int k = right - left + 1;
    cout << "? " << k << " ";
    for (int i = left; i <= right; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    int ones_first, ones_second;
    cin >> ones_first;
    cout << "? " << k - 1 << " ";
    for (int i = left; i <= right - 1; i++)
    {
        cout << i + 1 << " ";
    }
    cout << endl;
    cin >> ones_second;
    return (ones_second > ones_first);
}
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
        n *= 2;
        n++;
        int res_left = -1, res_mid = -1, res_right = -1;
        {
            // finding left pointer..
            int start = 0, end = n - 2;
            int left = start;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                bool curr = query_1(mid, n - 1);
                if (curr)
                {
                    // then the left end is from mid...end
                    start = mid + 1;
                    left = mid;
                }
                else
                {
                    // left pointer is from start..mid - 1..
                    end = mid - 1;
                }
            }
            res_left = left;
        }
        {
            // now similarly finding right pointer..
            int start = res_left + 2;
            int end = n - 1;
            int right = n - 1;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                bool curr = query_1(res_left, mid);
                if (curr)
                {
                    right = mid;
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            res_right = right;
        }

        // now we have left and right pointers..
        {
            int start = res_left + 1, end = res_right - 1;
            int MID = start;
            while (start <= end)
            {
                int mid = (start + end) / 2;
                bool curr = query_2(res_left, mid);
                if (curr)
                {
                    // one more check..
                    MID = mid;
                    end = mid - 1;
                }
                else
                {
                    // it is from mid + 1..end
                    start = mid + 1;
                }
            }
            res_mid = MID;
        }
        res_left++;
        res_mid++;
        res_right++;
        cout << "! " << res_left << " " << res_mid << " " << res_right << endl;
    }
    return 0;
}

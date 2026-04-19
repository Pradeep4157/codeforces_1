#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can keep an some ele x at an index i if for j = i + 1..n + 1. the max ele should be >= max_ele..

    this alone is not enough..

    for every  ele there are some smaller ele that i can put infront of it that is goin to be handled by arr[0]..

    after using up arr[i] all the elments should be non increasing..

    so either its decreasing or == arr[i - 1]...

    also the diff cannot be > 1 from the peak in the array..

    so we use arr[0] on some ele..

    and the peak till now is something..

    the current ele first of all should be <= peak..

    my goal is to make all the elements == largest element in the array..

    else atleast largest - 1..

    so i have some x largest numbers the no of ways they can rearrange is x!..

    now the remaining smaller elements are lets say y(count)..

    in these y i will try to make all these y  == largest..

    and there will be z elements that are == largest - 1..

    so the code is going to be :

    i make a for loop to find the no of elements that i am going to make == largest..

    does it matter which elements i use to make == largest and which one == largest - 1..

    i dont think so

    eg : x,y are 2 numbers and x > y ..

    if i choose to  make x == largest and y = largest - 1, ops = largest - x  + larges - 1 - y == 2*largest - x - 1 - y..

    similarly if i choose to make x == largest - 1 and y == largest,. ops = largest - 1 - x + largest - y == 2*largest - x - 1 - y which is same as first eqn..

    now that we know that elements that we select to make == largest / largest -  1 doesnt matter ..

    although the amount of addition that it is going to make needs to be calc..

    but  first thing is that we need to find whether this is possible or not..

    that mostly can be done using sums..

    total cost = no_of_curr_largest * largest + (n - no_of_curr_largest) * ( largest - 1)

    and then we just subtract the sum of array with this if the rem is <= 0 then yes it is possible else no because there are a lot of small elements..

    now when we know that it is possible..

    so what is the addition in the total ans..

    it is no_of_curr_largest ! * (n - no_of_curr_largest )! because we can rearrange them at any place but  relatively bigger needs to come before

    smaller..

    ig i will also have to multiply with ncno_of_largest because i might choose any elements to make as biggest..


    first i decide what is going to be my maximum ..

    i will try to make it as min as possible

    so that i can get better options on choosing thigs..(that's what i think..)

    now i have a max, i have decided that these many maxes i am going to create..

    now i have to choose from non max elements which elements i am going to include in max

    that is n - min_no_of_largest..



*/
const int mod = 998244353;
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = (res * i) % mod;
    }
    return res;
}
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int modInverse(int a)
{
    return power(a, mod - 2);
}

int nCr(int n, int r)
{
    if (r > n || r < 0)
        return 0;

    r = min(r, n - r);

    int ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = (ans * (n - r + i)) % mod;
        ans = (ans * modInverse(i)) % mod;
    }

    return ans;
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
        vector<int> arr(n + 1);
        for (int i = 0; i <= n; i++)
        {
            cin >> arr[i];
        }
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        int min_no_of_largest = 0;
        for (int i = 1; i <= n; i++)
        {
            int a = arr[i];
            if (a == maxi)
                min_no_of_largest++;
        }
        int non_largest = n - min_no_of_largest;
        int res = 0;

        for (int no_of_largest = min_no_of_largest; no_of_largest <= n; no_of_largest++)
        {

            int no_of_second_largest = n - no_of_largest;
            int req = (no_of_largest * maxi) + (no_of_second_largest * (maxi - 1));

            int rem = req - sum;
            if (rem <= 0)
            {
                // it is possible..
                // now the no of possible are factorial of
                int rem = no_of_largest - min_no_of_largest;
                int first = nCr(non_largest, rem);
                int curr = fact(no_of_largest) * fact(no_of_second_largest);

                curr %= mod;
                curr *= first;
                curr %= mod;
                // cout << curr << endl;
                res = curr;
                res %= mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for a number x S(x) is all the numbers sorted in ascending order..

    we need to find S(X) from X = 1...n

    so we are at some digit..

    the numbers that are already in ascending order are fine (ig)..

    for the numbers like 20,21, these numbers are the number that need to be added how to do this part..

    for the elements that are non decreasing for those numbers we just add them to the global res..



*/
string s;
int digits;
int dp_1[701][2][10];
const int mod = (int)(1e9 + 7);
int binpow(int base, int exp)
{
    int result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}
pair<int, int> recursion_1(int digit, bool is_tight, int prev_digit)
{
    if (digit == digits)
    {
        return {0, 1};
    }

    int limit = (is_tight ? s[digit] - '0' : 9ll);
    int res = 0;
    int curr_second = 0;
    for (int i = prev_digit; i <= limit; i++)
    {
        pair<int, int> next = recursion_1(digit + 1, (is_tight && (i == limit)), i);
        int times = next.second;
        int second = next.first;
        curr_second += second;
        int curr = (i * binpow(10, digits - digit - 1)) % mod;
        curr *= times;
        curr %= mod;
        curr += second;
        curr %= mod;
        res += curr;
        res %= mod;
    }
    return {res, limit - prev_digit + 1 + curr_second};
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    s = to_string(m);
    digits = s.size();
    memset(dp_1, -1, sizeof(dp_1));

    pair<int, int> res = recursion_1(0, 1, 0);
    cout << res.first << endl;
    return 0;
}

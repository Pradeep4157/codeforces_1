#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so candies at some node x is the sum of candies in the subtree at node x :

        which includes the candies at nodes x + sum of candies which can be taken from its children..

    now at some node x it has a candies and you want some squirrel to take y candies such that y y >= sum then it is false else i can do some exchanging..

    so if i have enough then a candies and it needs b candies :

        so total Ways is going to be : aCb..





*/
vector<int> min_req;
vector<int> c;
vector<vector<int>> adj;
vector<int> dp;
int res;
const int mod = 998244353;

const int MAXN = 1e6 + 5;

int fact[MAXN], invFact[MAXN];

int power(int a, int b)
{
    int res = 1;

    while (b > 0)
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }

    return res;
}

void precompute()
{
    fact[0] = 1;

    for (int i = 1; i < MAXN; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }

    invFact[MAXN - 1] = power(fact[MAXN - 1], mod - 2);

    for (int i = MAXN - 2; i >= 0; i--)
    {
        invFact[i] = (1LL * invFact[i + 1] * (i + 1)) % mod;
    }
}

int nCr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;

    int num = 1;

    for (int i = 0; i < r; i++)
    {
        num = (1LL * num * ((n - i) % mod)) % mod;
    }

    return (1LL * num * invFact[r]) % mod;
}
int dfs(int node)
{
    int child_contri = 0;
    for (auto child : adj[node])
    {
        child_contri += dfs(child);
    }
    // i have c[node] balls i need min_req balls, remaining balls i will send to my parent..
    int have = c[node];
    have += child_contri;
    int curr_req = min_req[node];
    int par_give = 0;
    if (curr_req > have)
    {
        dp[node] = 0;
    }
    else
    {
        dp[node] = nCr(have, curr_req);
        par_give = have - curr_req;
    }
    return par_give;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    precompute();
    while (t--)
    {
        int n;
        cin >> n;

        adj.resize(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int par;
            cin >> par;
            adj[par].push_back(i);
        }
        c.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i + 1];
        }
        min_req.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> min_req[i + 1];
        }
        dp.resize(n + 1);
        res = 1;
        dfs(1);
        for (int i = 1; i <= n; i++)
        {

            res *= dp[i];
            res %= mod;
        }

        cout << res << endl;
    }
    return 0;
}

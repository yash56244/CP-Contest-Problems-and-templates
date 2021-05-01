ll power(ll a, ll b, ll mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
bool check_composite(ll n, ll a, ll d, ll s)
{
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    FORL(i, 1, s - 1)
    {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
bool isPrime(ll n, int iter = 5)
{
    if (n < 2)
        return false;
    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
        {
            return true;
        }
        if (check_composite(n, a, d, s))
        {
            return false;
        }
    }
    return true;
}
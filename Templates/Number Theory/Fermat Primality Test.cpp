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
bool isPrime(ll n, int iter = 5)
{
    if (n < 4)
    {
        return n == 2 || n == 3;
    }
    FOR(i, iter)
    {
        int a = 2 + rand() % (n - 3);
        if (power(a, n - 1, n) != 1)
            return false;
    }
    return true;
}
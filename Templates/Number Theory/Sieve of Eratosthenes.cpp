vb prime;
void sieve(int n)
{
    prime.resize(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[p] = false;
            }
        }
    }
}
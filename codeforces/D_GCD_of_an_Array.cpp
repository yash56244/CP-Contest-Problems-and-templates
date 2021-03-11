//
#include <bits/stdc++.h>
#define lli long long int
#define inf 1000000000000000000
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;
const int sz = 2e5 + 5;
const lli mod = 1e9 + 7;
lli a[sz], s[6 * sz], lz[6 * sz];
lli gcd(lli a, lli b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
void make(lli left, lli right, lli index)
{
    if (left == right)
    {
        s[index] = a[left];
        lz[index] = 1;
        return;
    }
    lli mid = (left + right) / 2;
    make(left, mid, 2 * index + 1);
    make(mid + 1, right, 2 * index + 2);
    s[index] = gcd(s[2 * index + 1], s[2 * index + 2]);
    lz[index] = 1;
}
lli sum(lli left, lli right, lli start, lli end, lli index)
{
    if (lz[index] != 1)
    {
        s[index] = (s[index] * lz[index]);
        if (left != right)
        {
            lz[2 * index + 1] *= lz[index];
            lz[2 * index + 2] *= lz[index];
        }
        lz[index] = 1;
    }
    if (left > end || right < start)
    {
        return 0;
    }
    if (left >= start && right <= end)
    {
        return s[index];
    }
    lli mid = (left + right) / 2;
    lli l = sum(left, mid, start, end, 2 * index + 1);
    lli r = sum(mid + 1, right, start, end, 2 * index + 2);
    return gcd(l, r);
}
void update(lli left, lli right, lli start, lli end, lli x, lli index)
{
    if (lz[index] != 1)
    {
        s[index] = (s[index] * lz[index]);
        if (left != right)
        {
            lz[2 * index + 1] = (lz[2 * index + 1] * lz[index]);
            lz[2 * index + 2] = (lz[2 * index + 2] * lz[index]);
        }
        lz[index] = 1;
    }
    if (left > end || right < start)
    {
        return;
    }
    if (left >= start && right <= end)
    {
        s[index] = (s[index] * x);
        if (left != right)
        {
            lz[2 * index + 1] *= x;
            lz[2 * index + 2] *= x;
        }
        return;
    }
    lli mid = (left + right) / 2;
    update(left, mid, start, end, x, 2 * index + 1);
    update(mid + 1, right, start, end, x, 2 * index + 2);
    s[index] = gcd(s[2 * index + 1], s[2 * index + 2]);
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t-- > 0)
    {
        lli n, q;
        cin >> n >> q;
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        make(0, n, 0);
        for (lli i = 0; i < q; i++)
        {
            lli j, x;
            cin >> j >> x;
            j--;
            update(0, n, j, j, x, 0);
            cout << sum(0, n, 0, n - 1, 0) << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define ALL(v) v.begin(), v.end()
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logcontainer(container)   \
    for (auto &(e) : (container)) \
        cout << (e) << " ";       \
    cout << endl;
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<char, char> pcc;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef map<ll, ll> mapll;

class SegmentTree // SegmentTree st().
{
public:
    SegmentTree(ll count)
    {
        n = count;
        segtree.assign(2 * n, 0);
    }

    SegmentTree(vl &values) // Constructor for passing vector directly.
    {
        n = values.size();
        segtree = vl(2 * n);
        std::copy(values.begin(), values.end(), &segtree[0] + n);
        FORR(idx, n - 1, 1)
        {
            segtree[idx] = comb(segtree[idx * 2], segtree[idx * 2 + 1]);
        }
    }
    void print()
    {
        logcontainer(segtree);
    }
    ll comb(ll a, ll b) // Modify according to need.
    {
        return a + b;
    }
    void update(ll idx, ll val) // update value at idx to val.
    {
        idx += n;
        segtree[idx] = val;
        while (idx > 1)
        {
            idx /= 2;
            segtree[idx] = comb(segtree[2 * idx], segtree[2 * idx + 1]);
        }
    }

    ll query(ll left, ll right) // [l, r)
    {
        ll ret = 0;
        left += n;
        right += n;
        while (left < right)
        {
            if (left & 1)
                ret = comb(ret, segtree[left++]);
            if (right & 1)
                ret = comb(ret, segtree[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

private:
    ll n;
    vl segtree;
};

void yash56244()
{
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}
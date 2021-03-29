#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define AND &&
#define OR ||
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (int(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (int(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (int(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))
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
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef priority_queue<ll> maxheap;
typedef priority_queue<ll, vl, greater<ll>> minheap;
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

struct Mint
{
    ll v;
    explicit operator ll() const { return v; }
    Mint() { v = 0; }
    Mint(ll _v)
    {
        v = (-mod < _v && _v < mod) ? _v : _v % mod;
        if (v < 0)
            v += mod;
    }
    friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }

    Mint &operator+=(const Mint &m)
    {
        if ((v += m.v) >= mod)
            v -= mod;
        return *this;
    }
    Mint &operator-=(const Mint &m)
    {
        if ((v -= m.v) < 0)
            v += mod;
        return *this;
    }
    Mint &operator*=(const Mint &m)
    {
        v = v * m.v % mod;
        return *this;
    }
    Mint &operator/=(const Mint &m) { return (*this) *= inv(m); }

    friend Mint powr(Mint a, ll p)
    {
        Mint ans = 1;
        assert(p >= 0);
        for (; p; p /= 2, a *= a)
            if (p & 1)
                ans *= a;
        return ans;
    }

    friend Mint inv(const Mint &a)
    {
        assert(a.v != 0);
        return powr(a, mod - 2);
    }

    Mint operator-() const { return Mint(-v); }
    Mint &operator++() { return *this += 1; }
    Mint &operator--() { return *this -= 1; }
    Mint operator++(int)
    {
        Mint temp;
        temp.v = v++;
        return temp;
    }
    Mint operator--(int)
    {
        Mint temp;
        temp.v = v--;
        return temp;
    }

    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }

    friend ostream &operator<<(ostream &os, const Mint &m)
    {
        os << m.v;
        return os;
    }

    friend istream &operator>>(istream &is, Mint &m)
    {
        ll x;
        is >> x;
        m.v = x;
        return is;
    }
};

void yash56244() {}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
    }
    return 0;
}
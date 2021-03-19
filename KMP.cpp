#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define andd &&
#define orr ||
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define all(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

typedef long long int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef priority_queue<ll> maxheap;
typedef priority_queue<ll, vl, greater<ll>> minheap;
typedef map<ll, ll> mapll;
#define log(args...)                             \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
#define logarr(arr, a, b)            \
    for (int z = (a); z <= (b); z++) \
        cout << (arr[z]) << " ";     \
    cout << endl;
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

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

struct KMP // String matching algorithm
{
    vl ans;
    KMP(string pattern, string text)
    {
        vl lps = kmp(pattern + "@" + text);
        FORL(i, pattern.size(), text.size())
        {
            if (lps[i + pattern.size() + 1] == pattern.size())
            {
                ans.push_back(i - pattern.size());
            }
        }
    }
    vl getKMP() { return ans; } //return vector with values as starting index(0-based) of pattern in text.
    vl kmp(string s)
    {
        ll n = s.size();
        vl lps(n + 1);
        lps[0] = -1;
        FORL(i, 1, n)
        {
            for (lps[i] = lps[i - 1]; lps[i] != -1 && s[lps[i]] != s[i - 1];)
                lps[i] = lps[lps[i]];
            lps[i]++;
        }
        return lps;
    }
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
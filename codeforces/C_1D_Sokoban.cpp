#include <bits/stdc++.h>

using namespace std;

#define pi 3.1415926535897932384626433832795
#define endl "\n"
#define FOR(i, n) for (ll(i) = 0; (i) < (n); (i)++)
#define FORL(i, a, n) for (ll(i) = (a); (i) <= (n); (i)++)
#define FORR(i, a, n) for (ll(i) = (a); (i) >= (n); (i)--)
#define FORSQ(i, a, n) for (ll(i) = (a); (i) * (i) <= (n); ++(i))
#define FOREACH(a, b) for (auto &(a) : (b))
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (ll) v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
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
typedef vector<bool> vb;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef priority_queue<ll> PQMAX;
typedef priority_queue<ll, vector<ll>,
                       greater<ll>>
    PQMIN;
typedef set<ll> setll;
typedef map<ll, ll> mapll;

const ll inf = 1e15;
const ll mod = 1e9 + 7;

ll myfun(vl v1, vl v2)
{
    ll count = 0, temp = 0;
    for (ll i = 0; i < v2.size(); i++)
    {
        ll ab = lower_bound(ALL(v1), v2[i]) - v1.begin();
        ll k = v2[i];
        if (ab == 0)
        {
            continue;
        }
        if (ab == 1)
        {
            count = max(count, (ll)1);
            continue;
        }
        for (ll j = i; j < i + ab && j < v2.size(); j++)
        {
            if (v2[j] <= k || v2[j] >= ab + k - 1)
            {
                temp++;
            }
        }
        if (temp > count)
        {
            count = temp;
            temp = 0;
        }
    }
    return count;
}

void yash56244()
{
    ll n, m;
    cin >> n >> m;
    vl np, nn, mp, mn;
    FOR(i, n)
    {
        ll ai;
        cin >> ai;
        if (ai > 0)
        {
            np.push_back(ai);
        }
        else
        {
            nn.push_back(abs(ai));
        }
    }
    FOR(i, m)
    {
        ll ai;
        cin >> ai;
        if (ai > 0)
        {
            mp.push_back(ai);
        }
        else
        {
            mn.push_back(abs(ai));
        }
    }
    ll ans = 0;
    setll sn, sm;
    FOREACH(e, np)
    {
        sn.insert(e);
    }
    FOREACH(e, mp)
    {
        sm.insert(e);
    }
    FOREACH(e, sn)
    {
        if (sm.find(e) != sm.end())
        {
            sn.erase(e);
            sm.erase(e);
            ans++;
        }
    }
    np.clear();
    mp.clear();
    FOREACH(e, sn)
    {
        np.push_back(e);
    }
    FOREACH(e, sm)
    {
        mp.push_back(e);
    }
    sn.clear();
    sm.clear();
    FOREACH(e, nn)
    {
        sn.insert(e);
    }
    FOREACH(e, mn)
    {
        sm.insert(e);
    }
    FOREACH(e, sn)
    {
        if (sm.find(e) != sm.end())
        {
            sn.erase(e);
            sm.erase(e);
            ans++;
        }
    }
    nn.clear();
    mn.clear();
    FOREACH(e, sn)
    {
        nn.push_back(e);
    }
    FOREACH(e, sm)
    {
        mn.push_back(e);
    }
    ans += myfun(np, mp);
    ans += myfun(nn, mn);
    cout << ans << endl;
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
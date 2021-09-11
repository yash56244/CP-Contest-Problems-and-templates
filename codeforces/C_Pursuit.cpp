#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
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
const ll maxn = 2e6 + 5;

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

void yash56244()
{
    ll t, n, one_sum, two_sum, index, index_2, ans;
    one_sum = 0;
    two_sum = 0;
    ans = 0;
    cin >> n;
    vl one_v(n), two_v(n);
    FOR(i, n)
    {
        cin >> one_v[i];
    }

    FOR(i, n)
    {
        cin >> two_v[i];
    }

    sort(one_v.begin(), one_v.end(), greater<int>());
    sort(two_v.begin(), two_v.end(), greater<int>());

    for (int i = 0; i < n - (n / 4); i++)
    {
        one_sum += one_v[i];
        two_sum += two_v[i];
    }

    index = n - round(n / 4) - 1;
    index_2 = n - round(n / 4) - 1;

    if (one_sum >= two_sum)
    {
        cout << "0" << endl;
        return;
    }

    while (1)
    {
        ans++;
        n++;
        one_sum += 100;
        if (index_2 != two_v.size() - 1 && n % 4 != 0)
        {
            index_2++;
            two_sum += two_v[index_2];
        }
        if (index > -1 && n % 4 == 0)
        {
            one_sum -= one_v[index];
            index--;
        }
        if (one_sum >= two_sum)
        {
            break;
        }
    }
    cout << ans << endl;
}

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
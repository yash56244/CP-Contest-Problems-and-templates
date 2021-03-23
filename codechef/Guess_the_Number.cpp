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
bool isPerfectSquare(long double x)
{
    if (x >= 0)
    {

        long long sr = sqrt(x);

        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}
vector<ll> ans;
void pre()
{
    FORL(i, 1, 1000000)
    {
        if (i * i <= 1000000)
            ans.push_back(i * i);
        else
            break;
    }
}
bool flag = false;
void yash56244()
{
    ll inp;
    FOR(i, ans.size())
    {
        cout << ans[i] << endl;
        cout << flush;
        cin >> inp;
        if (inp == 1)
            break;
        if (inp == -1)
        {
            flag = true;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    pre();
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        yash56244();
        if (flag)
            break;
    }
    return 0;
}
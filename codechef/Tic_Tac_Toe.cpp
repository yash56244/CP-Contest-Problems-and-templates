#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define aur &&
#define ya ||
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

ll Mod(ll a, ll b)
{
    return (b + a % b) % b;
}

vector<string> v(3);
bool won(char c)
{
    if (v[0][0] == c && v[0][1] == c && v[0][2] == c)
    {
        return true;
    }
    else if (v[1][0] == c && v[1][1] == c && v[1][2] == c)
    {
        return true;
    }
    else if (v[2][0] == c && v[2][1] == c && v[2][2] == c)
    {
        return true;
    }
    else if (v[0][0] == c && v[1][0] == c && v[2][0] == c)
    {
        return true;
    }
    else if (v[0][1] == c && v[1][1] == c && v[2][1] == c)
    {
        return true;
    }
    else if (v[0][2] == c && v[1][2] == c && v[2][2] == c)
    {
        return true;
    }
    else if (v[0][0] == c && v[1][1] == c && v[2][2] == c)
    {
        return true;
    }
    else if (v[2][0] == c && v[1][1] == c && v[0][2] == c)
    {
        return true;
    }
    return false;
}

int count(char c)
{
    int cnt = 0;
    FOR(i, 3)
    {
        FOR(j, 3)
        {
            if (v[i][j] == c)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

void yash56244()
{
    v.clear();
    FOR(i, 3)
    {
        string s;
        cin >> s;
        v[i] = s;
    }
    bool xwon = won('X'), owon = won('O');
    int cntx = count('X'), cnto = count('O'), cnt_ = 9 - cntx - cnto;
    if (xwon && owon || (cntx < cnto) || (cntx > cnto + 1))
    {
        cout << 3;
    }
    else if (cntx == 0 && cnto == 0)
    {
        cout << 2;
    }
    else if (xwon && !owon && (cntx > cnto))
    {
        cout << 1;
    }
    else if (!xwon && owon && (cntx == cnto))
    {
        cout << 1;
    }
    else if (!xwon && !owon && (cnt_ == 0))
    {
        cout << 1;
    }
    else if (!xwon && !owon && (cnt_ > 0))
    {
        cout << 2;
    }
    else
    {
        cout << 3;
    }
    cout << endl;
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
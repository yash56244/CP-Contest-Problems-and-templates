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

ll arr[10];
ll h, m;

bool check(ll a, ll b)
{
    if (arr[a % 10] == -1 || arr[a / 10] == -1 || arr[b % 10] == -1 || arr[b / 10] == -1)
    {
        return false;
    }

    ll x = arr[b % 10] * 10 + arr[b / 10];
    ll y = arr[a % 10] * 10 + arr[a / 10];

    if (x < h && y < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void yash56244()
{
    memset(arr, -1, sizeof(arr));
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 5;
    arr[5] = 2;
    arr[8] = 8;
    cin >> h >> m;
    string str;
    cin >> str;
    ll a = (str[0] - '0') * 10 + str[1] - '0';
    ll b = (str[3] - '0') * 10 + str[4] - '0';
    while (!check(a, b))
    {
        b++;
        if (b == m)
            a++;
        b %= m;
        a %= h;
    }
    printf("%02d:", a);
    printf("%02d\n", b);
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
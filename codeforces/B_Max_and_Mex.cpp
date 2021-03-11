#include <bits/stdc++.h>

using namespace std;

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
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

void yash56244()
{
    ll n, k;
    cin >> n >> k;
    set<ll> s;
    FOR(i, n)
    {
        ll ai;
        cin >> ai;
        if (s.find(ai) == s.end())
        {
            s.insert(ai);
        }
    }
    if (k == 0)
    {
        cout << s.size() << endl;
    }
    else
    {
        int i = 0;
        while (i < s.size())
        {
            if (s.find(i) != s.end())
            {
                i++;
            }
            else
            {
                break;
            }
        }

        do
        {

            ll p = *--s.end();
            ll ans = (i + p + 1) / 2;
            if (p < i)
            {
                cout << i + k << endl;
                return;
            }
            if (ans == i)
            {
                s.insert(i);
                i++;
                while (i <= p)
                {
                    if (s.find(i) != s.end())
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                if (s.find(ans) != s.end())
                {
                    cout << s.size() << endl;
                    break;
                }
                else
                {
                    cout << s.size() + 1 << endl;
                    break;
                }
            }
        } while (true);
    }
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
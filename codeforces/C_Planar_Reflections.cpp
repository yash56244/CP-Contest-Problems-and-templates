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
#define log(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
#define logcontainer(container) \
  for (auto &(e) : (container)) \
    cout << (e) << " ";         \
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
ll nn;
ll dp[1001][1001][2];
ll rec(ll n, ll k, bool dir)
{
  if (k == 1 OR n == 0 OR n == nn + 1)
  {
    return 1;
  }
  if (dp[n][k][dir] != -1)
    return dp[n][k][dir];
  if (dir) //right
  {
    return dp[n][k][dir] = (rec(n + 1, k, true) + rec(n - 1, k - 1, false)) % mod;
  }
  else
  {
    return dp[n][k][dir] = (rec(n + 1, k - 1, true) + rec(n - 1, k, false)) % mod;
  }
}
void yash56244()
{
  ll k;
  cin >> nn >> k;
  memset(dp, -1, sizeof(dp));
  cout << rec(1, k, true) << endl;
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
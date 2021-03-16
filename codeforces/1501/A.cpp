// User: yash56244
// Problem: A. Alexey and Train
// Contest: Codeforces - Codeforces Round #707 (Div. 2, based on Moscow Open
// Olympiad in Informatics) URL: https://codeforces.com/contest/1501/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
typedef priority_queue<ll, vector<ll>, greater<ll>> PQMIN;
typedef map<ll, ll> mapll;

const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;

void yash56244() {
  ll n;
  cin >> n;
  ll a[n], b[n], tm[n];
  FOR(i, n) { cin >> a[i] >> b[i]; }
  FOR(i, n) { cin >> tm[i]; }
  ll ans = a[0] + tm[0];
  if (n == 1) {
    cout << ans << endl;
    return;
  }
  ans = max(ans + (ll)ceil((double)(b[0] - a[0]) / (double)2), b[0]);
  FORL(i, 1, n - 1) {
    ans += a[i] - b[i - 1] + tm[i];
    if (i != n - 1)
      ans = max(ans + (ll)ceil((double)(b[i] - a[i]) / (double)2), b[i]);
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin.tie(NULL);
  cout.tie(NULL);

  ll t = 1;
  cin >> t;
  while (t--) {
    yash56244();
  }
  return 0;
}
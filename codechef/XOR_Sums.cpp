#include <bits/stdc++.h>

using namespace std;

#define mod 998244353
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

ll modPower(ll x, ll y, ll p)
{
	ll res = 1;
	x = x % p;
	if (x == 0)
		return 0;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
ll modInverse(ll a, ll p)
{
	return modPower(a, p - 2, p);
}
ll modBinomial(ll n, ll k, ll p)
{
	ll numerator = 1;
	FOR(i, k)
	{
		numerator = (numerator * (n - i)) % p;
	}
	ll denominator = 1;
	FORL(i, 1, k)
	{
		denominator = (denominator * i) % p;
	}
	return (numerator * modInverse(denominator, p)) % p;
}

void yash56244()
{
	ll n;
	cin >> n;
	ll arr[n];
	ll xr = 0;
	FOR(i, n)
	{
		cin >> arr[i];
		xr += arr[i];
	}
	ll dp[n + 1];
	dp[1] = xr;
	FORL(i, 2, n)
	{
		ll dpi = 0;
		FOR(j, 32)
		{
			ll cnt1 = 0, cnt0 = 0;
			FOR(k, n)
			{
				if (arr[k] & (1 << j))
					cnt1++;
				else
					cnt0++;
			}
			ll ans = 0;
			for (ll l = 1; l <= i; l += 2)
			{
				if (l <= cnt1 and (i - l) <= cnt0)
				{
					ans += (modBinomial(cnt1, l, mod) * modBinomial(cnt0, i - l, mod)) % mod;
				}
			}
			dpi += (1 << j) * ans;
		}
		dp[i] = dp[i - 1] + dpi;
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll m;
		cin >> m;
		cout << dp[m] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	ll t = 1;
	// cin >> t;
	while (t--)
	{
		yash56244();
	}
	return 0;
}
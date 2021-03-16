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
void solve()
{
	int n;
	cin >> n;
	vector<int>
		v1(n), v(n);
	FOR(i, n)
	{
		cin >> v[i];
	}
	FOR(i, n)
	{
		v1[i] = false;
	}
	int x = v[n - 1];
	bool flag = true;
	for (int i = n - 1; i >= 0; i--)
	{
		int y = v[i];
		if (x == y)
		{
			flag = false;
		}
		if (y > x)
		{
			x = y;
		}
		if (x > 0)
		{
			v1[i] = true;
		}
		x--;
		if (flag)
		{
			if (y > x)
			{
				x = y;
			}
		}
	}
	for (auto i : v1)
	{
		if (i)
		{
			cout << 1 << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
	cout << endl;
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
		solve();
	}
	return 0;
}
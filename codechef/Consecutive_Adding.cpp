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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl

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
void yash56244()
{
	ll r, c, x;
	cin >> r >> c >> x;
	int a[r][c], b[r][c];
	FOR(i, r)
	{
		FOR(j, c)
		{
			cin >> a[i][j];
		}
	}
	FOR(i, r)
	{
		FOR(j, c)
		{
			cin >> b[i][j];
		}
	}
	FOR(i, r)
	{
		FOR(j, c)
		{
			a[i][j] -= b[i][j];
		}
	}
	bool possible = true;
	FORL(i, 1, min(x, r) - 1)
	{
		FORL(j, 1, min(x, c) - 1)
		{
			if (a[i][j] - a[i][0] -
					a[0][j] + a[0][0] !=
				0)
			{
				possible = false;
			}
		}
	}
	if (possible)
	{
		yes;
	}
	else
	{
		no;
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
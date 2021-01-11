#include <bits/stdc++.h>

using namespace std;

#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto &(a) : (b))
#define f first
#define s second
#define pb push_back
#define pon pop_back
#define mp make_pair
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll primeFactor(ll n)
{
	ll res = 0;
	while (n % 2 == 0)
	{
		n = n / 2;
		res++;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--)
	{
		ll w, h, n;
		cin >> w >> h >> n;
		if (w % 2 == 0 && h % 2 == 0)
		{
			ll pw1 = primeFactor(w);
			ll pw2 = primeFactor(h); 
			if (pow(2, pw1)*pow(2, pw2) >= n)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if (w % 2 == 0 && h % 2 != 0)
		{
			ll pw = primeFactor(w);
			if (pow(2, pw) >= n)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if (w % 2 != 0 && h % 2 == 0)
		{
			ll pw = primeFactor(h);
			if (pow(2, pw) >= n)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			if (n > 1)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YES" << endl;
			}
		}
	}
	return 0;
}

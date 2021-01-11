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


int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin>>n;
		ll arr[n];
		priority_queue<ll>pq;
		FOR(i, n){
			cin>>arr[i];
			pq.push(arr[i]);
		}
		ll alice = 0, bob = 0;
		ll i = 0;
		while(!pq.empty()){
			ll top = pq.top();
			if(i%2 == 0){
				if(top % 2 == 0){
					alice += top;
				}
			}else{
				if(top%2 != 0){
					bob+=top;
				}
			}
			pq.pop();
			i++;
		}
		if(alice>bob){
			cout<<"Alice"<<endl;
		}else if(alice<bob){
			cout<<"Bob"<<endl;
		}else{
			cout<<"Tie"<<endl;
		}
	}
	return 0;
}
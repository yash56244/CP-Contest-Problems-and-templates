#include <bits/stdc++.h>

using namespace std;

#define mod 1e9 + 7 
#define REP(i, a, b) for (int i=a; i<b; i++)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++) 
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++) 
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--) 
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a)) 
#define FOREACH(a, b) for (auto&(a) : (b)) 
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

ll findMin(ll arr[], ll n, ll sum)
{
    bool dp[n+1][sum+1];
 
    REP(i, 0, n + 1)
        dp[i][0] = true;
 
    REP(i, 1, sum + 1)
        dp[0][i] = false;
 
    REP(i, 1, n + 1)
    {
        REP(j, 1, sum + 1)
        {
            dp[i][j] = dp[i-1][j];
 
            if (arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }
  
    ll diff = INT_MAX;
     
    for (ll j=sum/2; j>=0; j--)
    {
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--){
		ll n, k;
		cin>>n>>k;
		ll arr[n], ts = 0;             
		REP(i, 0, n){
			cin>>arr[i];
			ts += arr[i];
		}
		if(ts < 2*k){
			cout<<-1<<endl;
			continue;
		}
		sort(arr, arr+n, greater<int>());
		ll sum = 0, i = 0;
		while(sum < 2*k){
			sum += arr[i];
			i++;
		}
		ll diff = findMin(arr, i, sum);
		if(sum-diff>= 2*k){
			cout<<i<<endl;
			continue;
		}
		while(sum-diff < 2*k && i < n){
			sum += arr[i];
			diff = findMin(arr, i + 1, sum);
			i++;
		}
		if(i == n && sum-diff < 2*k){
			cout<<-1<<endl;
		}else{
			cout<<i<<endl;
		}
	}
	return 0;
}
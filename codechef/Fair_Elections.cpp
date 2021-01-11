#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n, m;
		cin>>n>>m;
		ll ai[n], bi[m];
		ll jj1 = 0, jj2 = 0;
		for(int i = 0; i < n; i++){
			cin>>ai[i];
			jj1 += ai[i];
		}
		for(int i = 0; i < m; i++){
			cin>>bi[i];
			jj2 += bi[i];
		}
		if(jj1 > jj2){
			cout<<0<<endl;
		}
		else{
			sort(ai, ai + n);
			sort(bi, bi + m);
			ll aii = 0, bii = m - 1, swaps = 0;
			bool flag = false;
			while(ai[aii] < bi[bii]){
				ll diff = bi[bii] - ai[aii];
				jj1 += diff;
				jj2 -= diff;
				swaps++;
				if(jj1 > jj2){
					flag = true;
					break;
				}
				aii++;
				bii--;
			}
			if(flag){
				cout<<swaps<<endl;				
			}else{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}

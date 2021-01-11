#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
		ll n,k, x, y;
		cin>>n>>k>>x>>y;
		if(x == y){
			cout<<n<<" "<<n<<endl;
		}else{
			if(y < x){
				if(k%4 == 0){
					cout<<x-y<<" "<<0<<endl;
				}else if (k%4 == 1){
					cout<<n<<" "<<n-x+y<<endl;
				}else if (k%4 == 2){
					cout<<n-x+y<<" "<<n<<endl;
				}else{
					cout<<0<<" "<<x-y<<endl;
				}
			}
			else{
				if(k%4 == 0){
					cout<<0<<" "<<y-x<<endl;
				}else if (k%4 == 1){
					cout<<n+x-y<<" "<<n<<endl;
				}else if (k%4 == 2){
					cout<<n<<" "<<n+x-y<<endl;
				}else{
					cout<<y-x<<" "<<0<<endl;
				}
			}
		}
	}
	return 0;
}

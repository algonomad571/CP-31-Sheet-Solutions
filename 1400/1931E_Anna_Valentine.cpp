#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	
	while(t--){
	    ll n,m;
        cin>>n>>m;

        vector<ll> z;
        ll totalDigits=0;

        for(int i=0; i<n; i++){
            ll x;
            cin>>x;

            totalDigits+=to_string(x).size();

            ll tz=0;
            while(x%10==0){
                tz++;
                x/=10;
            }
            z.push_back(tz);
        }

        sort(z.rbegin(),z.rend());

        for(int i=0; i<n; i+=2){
            totalDigits-=z[i];
        } 

        cout<<(totalDigits>m ? "Sasha":"Anna")<<endl;
	}
	return 0;
}
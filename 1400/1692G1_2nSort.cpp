#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    ll ans=0;
    int len=0;

    for(int i=0;i<n-1;i++){
        if(a[i]<2*a[i+1]){
            len++;
        }
        else{
            if(len>=k)ans+=len-k+1;
            len=0;
        }
    }

    if(len>=k) ans+=len-k+1;

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    
    while(t--){
        solve();
    }

    return 0;
}
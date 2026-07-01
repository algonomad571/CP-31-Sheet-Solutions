#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long n,x,y;
    cin>>n>>x>>y;

    int p=x&1;

    for(int i=0; i<n; i++){
        long long a;
        cin>>a;

        p^=(a&1);
    }

    if(p==(y&1)) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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
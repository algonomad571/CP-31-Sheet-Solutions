#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int ans=-1;
    int x=INT_MAX, y=INT_MAX;

    for(int i=0; i<n; i++){
        if(x>y)swap(x,y);

        if(a[i]<=x){
            x=a[i];
        }
        if(a[i]<=y){
            y=a[i];
        }
        else{
            x=a[i];
            ans++;
        }
    }
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
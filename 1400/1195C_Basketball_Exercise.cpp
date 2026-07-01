#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;

    vector<ll>a(n+1),b(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<vector<ll>>dp(n+1,vector<ll>(3,0));

    for(int i=1;i<=n;i++){
        dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+b[i];
    }

    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
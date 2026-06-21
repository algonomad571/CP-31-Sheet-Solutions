#include<bits/stdc++.h>
using namespace std;

int MOD=1000000007;

void solve(){
    int n,k;
    cin>>n>>k;

    vector<vector<long long>> dp(k+1,vector<long long>(n+1,0));

    for(int x=1; x<=n; x++){
        dp[1][x]=1;
    }

    for(int l=2; l<=k; l++){
        for(int x=1;x<=n;x++){
            for(int m=x; m<=n; m+=x){
                dp[l][m]+=dp[l-1][x];
                dp[l][m]%=MOD;
            }
        }
    }

    long long ans=0;
    for(int x=1; x<=n; x++){
        ans=(ans+dp[k][x])%MOD;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}
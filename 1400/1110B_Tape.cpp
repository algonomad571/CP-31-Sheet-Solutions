#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<int>gap;

    for(int i=0;i<n-1;i++){
        gap.push_back(a[i+1]-a[i]-1);
    }

    sort(gap.begin(),gap.end());
    int ans=0;
    for(int i=0;i<n-k;i++){
        ans+=gap[i];
    }
    cout<<ans+n<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
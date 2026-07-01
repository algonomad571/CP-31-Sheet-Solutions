#include<bits/stdc++.h>
using namespace std;

const int LOG=20;

void solve(){
    int n;
    cin>>n;

    vector<vector<int>>st(LOG,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        cin>>st[0][i];
    }

    for(int j=1;j<LOG;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[j][i]=st[j-1][i]&st[j-1][i+(1<<(j-1))];
        }
    }

    vector<int>lg(n+1);

    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }

    int q;
    cin>>q;

    while(q--){
        int l,k;
        cin>>l>>k;

        if(st[0][l]<k){
            cout<<-1<<" ";
            continue;
        }

        int lo=l,hi=n,ans=l;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            int len=mid-l+1;
            int j=lg[len];

            int cur=st[j][l]&st[j][mid-(1<<j)+1];

            if(cur>=k){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        cout<<ans<<" ";
    }

    cout<<endl;
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
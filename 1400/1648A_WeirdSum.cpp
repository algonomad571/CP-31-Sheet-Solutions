    #include<bits/stdc++.h>
    using namespace std;

    using ll=long long;

    ll calc(vector<int>& v){
        sort(v.begin(),v.end());

        ll ans=0;
        ll pref=0;

        for(int i=0; i<(int)v.size();i++){
            ans+=1LL*v[i]*i-pref;
            pref+=v[i];
        }

        return ans;
    }

    void solve(){
        int n,m;
        cin>>n>>m;

        unordered_map<int, vector<int>> rows, cols;

        for(int i=1;i<=n;i++){
            for(int j=1; j<=m; j++){
                int x;
                cin>>x;

                rows[x].push_back(i);
                cols[x].push_back(j);
            }
        }

        ll ans=0;

        for (auto &[color, r] : rows) {
            ans += calc(r);
        }

        for (auto &[color, c] : cols) {
            ans += calc(c);
        }

        cout<<ans<<endl;
    }

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        solve();

        return 0;
    }
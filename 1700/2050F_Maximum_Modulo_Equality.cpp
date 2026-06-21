#include<bits/stdc++.h>
using namespace std;

using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;

        vector<ll> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i];

        if(n==1){
            while(q--){
                int l,r;
                cin>>l>>r;

                cout<<0<<" ";
            }
            cout<<endl;
            continue;
        }

        vector<ll> diff(n+1);

        for(int i=2; i<=n; i++)diff[i-1]=abs(a[i]-a[i-1]);

        int LOG=20;
        vector<vector<ll>> st(LOG, vector<ll>(n));

        for(int i=1; i<n; i++)st[0][i]=diff[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i + (1 << j) - 1 < n; i++) {
                st[j][i] = gcd(
                    st[j - 1][i],
                    st[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        auto rangeGcd = [&](int L, int R) {
            int len = R - L + 1;
            int k = 31 - __builtin_clz(len);
            return gcd(
                st[k][L],
                st[k][R - (1 << k) + 1]
            );
        };

        while (q--) {
            int l, r;
            cin >> l >> r;

            if (l == r) {
                cout << 0;
            } else {
                cout << rangeGcd(l, r - 1);
            }

            cout << " ";
        }

        cout<<endl;
    }

    return 0;
}
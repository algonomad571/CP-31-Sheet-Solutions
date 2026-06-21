#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long sum=0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum+=a[i];
        }

        sort(a.begin(), a.end());

        long long k = 0;
        long long j = 0;

        for(int i=0; i<n; i++){
            k+=a[i];

            if(k>(sum+1)/2){
                break;
            }
            j++;
        }
        cout<<((sum+1)/2)+n-j<<endl;
    }

    return 0;
}


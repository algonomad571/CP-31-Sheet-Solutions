#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    if (n > m) {
        cout << 0 << "\n";
        return 0;
    }

    long long ans = 1;

    for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        long long diff = abs(a[i] - a[j]) % m;
        ans = (ans * diff) % m;
    }
}

    cout << ans << "\n";
}
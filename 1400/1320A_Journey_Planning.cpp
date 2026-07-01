#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  unordered_map<long long, long long> mp;
  long long ans = 0;

  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;

    mp[x - i] += x;
    ans = max(ans, (long long)mp[x - i]);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
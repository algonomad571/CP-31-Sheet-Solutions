#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll countContributions(const vector<ll>& bitArray) {
    ll n = bitArray.size();
    ll result = 0;
    ll oddSum = 0, evenSum = 0;
    ll oddCount = 0, evenCount = 0;

    for (ll i = 0; i < n; ++i) {
        if (bitArray[i] == 1) {
            swap(oddSum, evenSum);
            swap(oddCount, evenCount);
            oddSum += i;
            oddCount++;
        } else {
            evenSum += i;
            evenCount++;
        }

        oddSum %= MOD;
        evenSum %= MOD;

        ll term = ((i + 1) * oddCount - oddSum) % MOD;
        result = (result + (term + MOD) % MOD) % MOD;
    }

    return result;
}

int main() {
    ll n;
    cin >> n;

    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ll total = 0;

    for (ll bit = 0; bit < 31; ++bit) {
        vector<ll> bitArray(n);
        for (ll i = 0; i < n; ++i) {
            bitArray[i] = (arr[i] >> bit) & 1;
        }

        ll contribution = countContributions(bitArray);
        ll powerOfTwo = (1LL << bit) % MOD;
        total = (total + (contribution * powerOfTwo) % MOD) % MOD;
    }

    cout << total << endl;
    return 0;
}

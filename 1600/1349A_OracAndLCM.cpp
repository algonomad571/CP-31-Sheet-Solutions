#include <bits/stdc++.h>
using namespace std;

const int MAXA = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> freq(MAXA + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    long long ans = 1;

    // Sieve for primes
    vector<bool> is_prime(MAXA + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= MAXA; i++) {
        if (!is_prime[i]) continue;

        // mark multiples
        for (int j = i * 2; j <= MAXA; j += i)
            is_prime[j] = false;

        long long p = i;
        int exponent = 0;

        while (p <= MAXA) {
            int count = 0;

            // count numbers divisible by p^k
            for (int j = p; j <= MAXA; j += p) {
                count += freq[j];
            }

            if (count >= n - 1) {
                exponent++;
                p *= i;
            } else {
                break;
            }
        }

        // multiply p^exponent
        for (int e = 0; e < exponent; e++) {
            ans *= i;
        }
    }

    cout << ans << "\n";
}
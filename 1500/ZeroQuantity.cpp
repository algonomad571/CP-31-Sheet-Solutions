#include <bits/stdc++.h>
using namespace std;
/*
Okay so the idea here is to count how many times the same ratio (b[i] / a[i]) appears.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);   
    int totalCount;
    cin >> totalCount;

    vector<long long> arrA(totalCount);
    vector<long long> arrB(totalCount);

    // Read first array
    for (int idx = 0; idx < totalCount; idx++) {
        cin >> arrA[idx];
    }

    // Read second array (could merge loops, but keeping it simple)
    for (int i = 0; i < totalCount; i++) {
        cin >> arrB[i];
    }

    long long zeroZeroPairs = 0;  // counts cases where both a[i] and b[i] are zero
    map<pair<long long, long long>, long long> ratioCounter;

    for (int i = 0; i < totalCount; i++) {

        long long currentA = arrA[i];
        long long currentB = arrB[i];

        // Special handling when A is zero
        if (currentA == 0) {
            if (currentB == 0) {
                // both zero -> "free" match
                zeroZeroPairs++;
            }
            // if A == 0 but B != 0, we just ignore it
        } else {

            long long numerator = currentB;
            long long denominator = currentA;

            // Reduce fraction (not super optimized but clear enough)
            long long divisor = __gcd(llabs(numerator), llabs(denominator));
            if (divisor != 0) {   // technically gcd won't be zero here, but just being safe
                numerator /= divisor;
                denominator /= divisor;
            }

            // Keep denominator positive for consistent storage
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }

            // Increment frequency
            ratioCounter[make_pair(numerator, denominator)]++;

            // I thought about using unordered_map for speed,
            // but map is fine unless constraints are huge.
        }
    }

    long long maxFrequency = 0;

    // Find the highest frequency among all normalized ratios
    for (auto it = ratioCounter.begin(); it != ratioCounter.end(); ++it) {
        if (it->second > maxFrequency) {
            maxFrequency = it->second;
        }
    }

    // Final result adds the "free" zero-zero pairs
    long long answer = maxFrequency + zeroZeroPairs;

    cout << answer << "\n";

    return 0;
}
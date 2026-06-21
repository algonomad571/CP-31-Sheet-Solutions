#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, d;
    cin >> a >> d;
    int n;
    cin >> n;

    double perimeter = 4.0 * a;

    for (int i = 1; i <= n; i++) {
        double s = fmod(i * d, perimeter);

        double x, y;

        if (s < a) {
            x = s;
            y = 0.0;
        }
        else if (s < 2 * a) {
            x = a;
            y = s - a;
        }
        else if (s < 3 * a) {
            x = 3 * a - s;
            y = a;
        }
        else {
            x = 0.0;
            y = 4 * a - s;
        }

        printf("%.10f %.10f\n", x, y);
    }

    return 0;
}

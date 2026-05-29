#include <bits/stdc++.h>
using namespace std;

int main() {
    const int N = 100000;
    vector<bool> isPrime(N + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << ",";
        }
    }

    return 0;
}

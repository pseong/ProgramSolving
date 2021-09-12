#include <bits/stdc++.h>
using namespace std;

int not_prime[1000001]{ 0 };
vector<int> primes;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    not_prime[0] = 1;
    not_prime[1] = 1;
    for(int i = 2; i <= 1000000; i++) {
        if(!not_prime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 1000000; j += i) {
                not_prime[j] = 1;
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int res = 0;
        for(int i : primes) {
            if(i > n / 2) break;
            if(not_prime[n - i] == 0) res++;
        }
        cout << res << '\n';
    }

    return 0;
}
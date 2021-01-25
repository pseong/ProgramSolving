#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    bool prime[10000001];
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;

    for(int i = 1; i*i <= 10000000; i++) {
        if(!prime[i]) continue;
        for(int j = 2*i; j <= 1000000; j += i) {
            prime[j] = 0;
        }
    }

    while(n%2 == 0) {
        cout << 2 << '\n';
        n /= 2;
    }
    for(int i = 3; i <= 10000000; i+=2) {
        if(prime[i]) {
            while(n%i == 0) {
                cout << i << '\n';
                n /= i;
            }
        }
        if(n == 1) break;
    }
}
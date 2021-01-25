#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool prime[1000000]{ 0 };
    for(int i = 3; i < 1000000; i += 2) prime[i] = 1;

    prime[1] = 0;
    for(int i = 2; i < sqrt(1000000); i++) {
        if(prime[i] == 0) continue;
        for(int j = i * 2; j < 1000000; j += i)
            prime[j] = 0;
    }

    while(1) {
        int n;
        cin >> n;
        if(n == 0) break;

        int left = 3;

        while(1) {
            if(n - left < 0) {
                cout << "Goldbach's conjecture is wrong.\n";
                break;
            }
            if(prime[left] == 1 && prime[n - left] == 1) {
                cout << n << " = " << left << 
                    " + " << n - left << '\n';
                break;
            }
            left += 2;
        }
    }
}
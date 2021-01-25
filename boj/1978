#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int result{ 0 };
    while(n--) {
        int i;
        cin >> i;
        if(i == 1) continue;
        bool is_prime{ 1 };
        for(int j = 1; j < i; j++) {
            if(gcd(i, j) != 1) {
                is_prime = 0;
                break;
            }
        }
        if(is_prime) result++;
    }
    cout << result;
}
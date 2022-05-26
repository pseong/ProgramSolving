#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<int> primes;
bool isp(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> k >> n;
    for (int i=2020; primes.size()<30; i++) {
        if (isp(i)) primes.push_back(i);
    }

    for (int i=0; i<k; i++) {
        for (int j=1; j<=n; j++) {
            cout << primes[i]*j << ' ';
        }
        cout << '\n';
    }
}
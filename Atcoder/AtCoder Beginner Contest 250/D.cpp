#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<bool> primes(1000001, 1);
    vector<ll> p;
    primes[0] = 0;
    primes[1] = 0;
    for (int i=2; i<=1000000; i++) {
        if (primes[i] == 1) {
            p.push_back(i);
            for (int j=i*2; j<=1000000; j+=i) {
                primes[j] = 0;
            }
        } 
    }
    
    ll ans = 0;
    for (ll i=1; i<p.size(); i++) {
        ll three = p[i]*p[i]*p[i];
        if (three > n) break;
        ll lo = 0;
        ll hi = i-1;
        ll a = -1;
        while (lo <= hi) {
            ll mid = (lo+hi)/2;
            if ((__int128_t)p[mid]*three <= n) {
                a = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        ans += a+1;
    }
    cout << ans;
}
const int MAX_PRIME = 1010101;
ll prime[MAX_PRIME];
vector<ll> primes;

void init_prime() {
    for (int i=2; i<MAX_PRIME; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<MAX_PRIME; j+=i) {
                prime[j] = 1;
            }
        }
    }
}

vector<ll> get_factors(ll n) {
    vector<ll> v;
    for (ll p : primes) {
        if (p*p > n) break;
        if (n%p == 0) {
            v.push_back(p);
            v.push_back(n/p);
            while (n%p == 0) {
                n /= p;
            }
        }
    }
    if (n != 1) v.push_back(n);
    sort(v.begin(), v.end());
    return v;
}
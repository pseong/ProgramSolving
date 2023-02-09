#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }
 
bool prime[101010];
vector<int> primes;
 
void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=1; i<n; i++) {
        if (v[i] == v[i-1] && v[i] != 1) {
            yes();
            return;
        }
    }
    set<int> st;
    for (int i=0; i<n; i++) {
        for (int p : primes) {
            if (v[i] % p == 0) {
                if (st.find(p) != st.end()) {
                    yes();
                    return;
                }
                st.insert(p);
                while (v[i] % p == 0) v[i] /= p;
            }
        }
        if (v[i] > 1) {
            if (st.find(v[i]) != st.end()) {
                yes();
                return;
            }
            st.insert(v[i]);
        }
    }
    no();
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    for (int i=2; i<=32000; i++) {
        if (prime[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=32000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        for (int j=0; j<10; j++) {
            v[i] += v[i] % 10;
        }
        while (v[i] % 10 != 2 && v[i] % 10 != 0) {
            v[i] += v[i] % 10;
        }
        if (v[i] % 10 == 2) {
            v[i] %= 20;
        }
    }
    if (v == vector<int>(n, v[0])) yes();
    else no();
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "NO\n"; }
void yes() { cout << "YES\n"; }

void solve() {
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    for (auto c : {'a', 'b', 'c'}) {
        if (count(s.begin(), s.end(), c) != count(t.begin(), t.end(), c)) {
            no();
            return;
        }
    }

    string s1, t1;
    vector<int> a, b;
    for (int i=0; i<n; i++) {
        if (s[i] != 'b') {
            s1.push_back(s[i]);
            a.push_back(i);
        }
    }
    for (int i=0; i<n; i++) {
        if (t[i] != 'b') {
            t1.push_back(t[i]);
            b.push_back(i);
        }
    }

    if (s1 != t1) {
        no();
        return;
    }

    n = s1.size();
    for (int i=0; i<n; i++) {
        if (s1[i] == 'a' && a[i] > b[i]) {
            no();
            return;
        }
        else if (s1[i] == 'c' && a[i] < b[i]) {
            no();
            return;
        }
    }
    yes();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
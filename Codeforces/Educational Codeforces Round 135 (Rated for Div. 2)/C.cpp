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
    vector<multiset<int>> A(10), B(10);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        A[to_string(x).size()].insert(x);
    }
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        B[to_string(x).size()].insert(x);
    }
    ll ans = 0;
    for (int k=9; k>=1; k--) {
        vector<int> e;
        for (auto x : A[k]) {
            if (B[k].count(x)) B[k].erase(B[k].find(x)), e.push_back(x);
        }
        for (auto x : e) {
            A[k].erase(A[k].find(x));
        }
        if (k == 1) break;
        ans += A[k].size() + B[k].size();
        for (auto x : A[k]) {
            A[to_string(k).size()].insert(k);
        }
        for (auto x : B[k]) {
            B[to_string(k).size()].insert(k);
        }
    }
    for (auto x : A[1]) {
        if (x != 1) ans++;
    }
    for (auto x : B[1]) {
        if (x != 1) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#if TEST
    freopen("/Users/macrent/ProgramSolving/input.txt", "r", stdin);
#endif

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
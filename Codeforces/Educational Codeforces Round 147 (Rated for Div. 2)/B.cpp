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
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    int l = -1;
    int r = -1;
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) r = i;
    }
    for (int i=n-1; i>=0; i--) {
        if (a[i] != b[i]) l = i;
    }
    if (l == -1) {
        cout << 1 << ' ' << n << '\n';
        return;
    }
    int mn = *min_element(a.begin() + l, a.begin() + r + 1);
    int mx = *max_element(a.begin() + l, a.begin() + r + 1);
    while (l > 0 && b[l-1] <= mn) {
        mn = b[l-1];
        l--;
    }
    while (r < n-1 && b[r+1] >= mx) {
        mx = b[r+1];
        r++;
    }
    cout << l + 1 << ' ' << r + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
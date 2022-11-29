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

vector<int> v(20, 0);
bool fail;

void up(int idx) {
    if (idx == 10) {
        fail = true;
        return;
    }
    if (v[idx] < 9 && (v[idx + 1] == 0 || v[idx + 1] > v[idx] + 1)) {
        if (idx != 0 && v[idx] == 0) v[idx] = idx;
        else v[idx]++;
    }
    else {
        v[idx] = idx;
        up(idx + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        up(0);
    }
    if (fail) {
        cout << -1 << '\n';
        return 0;
    }
    ll ans = 0;
    for (int i=9; i>=0; i--) {
        ans *= 10;
        ans += v[i];
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#define int long long
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

vector<int> v;
int n;

bool cal(int mid) {
    vector<int> tmp = v;
    vector<int> x(n, 0);
    for (int i=n-1; i>=0; i--) {
        if (tmp[i]+min(mid, x[i]) < mid) return false;
        if (i >= 2) {
            int d = (tmp[i]+min(mid, x[i])-mid) / 3;
            x[i-1] += d;
            x[i-2] += 2*d;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    v.assign(n, 0);
    for (int i=0; i<n; i++) cin >> v[i];
    int lo = 0;
    int hi = 1e9;
    vector<int> tmp;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool b = cal(mid);
        if (b == false) {
            hi = mid - 1;
        }
        else {
            ans = mid;
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
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

int n;

bool sol(vector<int> v, int k) {
    int j = k + 1;
    ll now = 0;
    ll mx = 0;
    for (int i=k; i>=1; i--) {
        if (now + v[i] >= 0) {
            now += v[i];
            mx = max(mx, now);
        }
        else {
            ll g = mx;
            while (j <= n && g - mx < -(now + v[i])) {
                g += v[j];
                if (g < 0) return false;
                j++;
            }
            if (g - mx < -(now + v[i])) return false;
            now += g - mx;
            mx = g;
            i++;
        }
    }
    return true;
}

void solve(int CASE) {
    int k;
    cin >> n >> k;
    vector<int> v(n + 1), rv(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        rv[n+1-i] = v[i];
    }
    if (sol(v, k) || sol(rv, n + 1 - k)) yes();
    else no();
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
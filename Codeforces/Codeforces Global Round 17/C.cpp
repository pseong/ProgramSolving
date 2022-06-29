#include <bits/stdc++.h>
#define int long long
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
vector<int> a, b;

bool poss(int x) {
    int cnt = 1;
    for (int i=1; i<=n; i++) {
        if (a[i] >= x-cnt && b[i] >= cnt-1) cnt++;
        if (cnt == x+1) return true;
    }
    return false;
}

void solve() {
    cin >> n;
    a.resize(n+1);
    b.resize(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    int lo = 1;
    int hi = n;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool cal = poss(mid);
        if (cal) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
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
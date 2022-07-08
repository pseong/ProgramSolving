#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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

vector<int> v, task;
int n, m;

bool calc(int m) {
    int left = 0;
    for (int i=1; i<=n; i++) {
        if (task[i] <= m) {
            left -= (m-task[i]) / 2;   
        }
        else {
            left += task[i]-m;
        }
    }
    if (left > 0) return false;
    else return true;
}

void solve() {
    cin >> n >> m;
    v.assign(m, 0);
    task.assign(n+1, 0);
    for (int i=0; i<m; i++) {
        cin >> v[i];
        task[v[i]]++;
    }
    int lo = 1;
    int hi = 400000;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        bool cal = calc(mid);
        if (cal) {
            ans = mid;
            hi = mid - 1;
        }
        else {
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
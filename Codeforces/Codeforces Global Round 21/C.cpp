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

int m;
vector<pi> cal(vector<int>& a) {
    vector<pi> v;
    int n = a.size();
    for (int i=0; i<n; i++) {
        int go = a[i];
        int cnt = 1;
        while (go % m == 0) {
            go /= m;
            cnt *= m;
        }
        v.push_back({go, cnt});
    }
    vector<pi> ans;
    for (int i=0; i<(int) v.size(); i++) {
        if (ans.empty()) ans.push_back(v[i]);
        else if (ans.back().first == v[i].first) {
            ans.back().second += v[i].second;
        }
        else ans.push_back(v[i]);
    }
    return ans;
}

void solve() {
    int n; cin >> n >> m;
    vector<int> a(n);
    deque<pi> dq;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    int k; cin >> k;
    vector<int> b(k);
    for (int i=0; i<k; i++) {
        cin >> b[i];
    }
    vector<pi> A = cal(a);
    vector<pi> B = cal(b);
    if (A == B) yes();
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
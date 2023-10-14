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

double dist(vector<double> a, vector<double> b) {
    return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

void solve(int CASE) {
    vector<double> home(2), a(2), b(2), zero{0, 0};
    cin >> home[0] >> home[1];
    cin >> a[0] >> a[1];
    cin >> b[0] >> b[1];
    double ans1 = max(dist(a, zero), dist(a, home));
    double ans2 = max(dist(b, zero), dist(b, home));
    double ans3 = max({dist(a, zero), dist(b, home), dist(a, b) / 2});
    double ans4 = max({dist(a, home), dist(b, zero), dist(a, b) / 2});
    cout << fixed << setprecision(9) << min({ans1, ans2, ans3, ans4}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
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
    string s;
    cin >> n >> s;
    s.insert(s.begin(), ' ');
    vector<int> pref(n + 1);
    for (int i=2; i<=n; i++) {
        pref[i] = pref[i-1];
        if (s[i] != s[i-1]) pref[i]++;
    }
    
    int ans = pref[n];
    for (int i=1; i<n; i++) {
        int c = pref[i] + (s[1] == '1');
        int d = pref[n] - pref[i+1];
        if (c%2) {
            if (s[i+1] == '1') d++;
        }
        else {
            if (s[i+1] == '0') d++;
        }
        ans = min(ans, c + d);
    }

    cout << ans << '\n';
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
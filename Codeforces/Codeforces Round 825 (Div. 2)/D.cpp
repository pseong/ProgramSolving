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
    int o = 0;
    for (int i=0; i<n*2; i++) {
        if (s[i] == '1') o++;
    }
    if (o%2) {
        cout << -1 << '\n';
        return;
    }
    char c = '0';
    vector<int> ans;
    for (int i=0; i<n*2; i+=2) {
        if (s[i] == s[i+1]) continue;
        if (s[i] == c) {
            ans.push_back(i+1);
            c = s[i+1];
        }
        else {
            ans.push_back(i);
            c = s[i];
        }
    }
    srt(ans);
    cout << ans.size() << ' ';
    for (int a : ans) cout << a + 1 << ' ';
    cout << '\n';
    for (int i=1; i<=n*2; i+=2) cout << i << ' ';
    cout << '\n';
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
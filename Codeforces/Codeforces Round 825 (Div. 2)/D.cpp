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
    int o = 0, z = 0;
    for (int i=0; i<n*2; i++) {
        if (s[i] == '1') o++;
        else z++;
    }
    if (o%2 || z%2) {
        cout << -1 << '\n';
        return;
    }
    int l = 0;
    int r = n*2-1;
    vector<int> ans;
    char c = ' ';
    while (true) {
        while (l < r && s[l] == s[l+1]) l += 2;
        while (l < r && s[r] == s[r-1]) r -= 2;
        if (l > r) break;
        if (s[l] == s[r]) {
            if (c == ' ' || c == s[l]) {
                ans.push_back(r);
                ans.push_back(l+1);
                c = s[l+1];
                swap(s[r], s[l+1]);
            }
            else {
                ans.push_back(r-1);
                ans.push_back(l);
                c = s[l];
                swap(s[r-1], s[l]);
            }
        }
        else {
            if (c == ' ' || c != s[l]) {
                ans.push_back(r);
                ans.push_back(l);
                c = s[l];
                swap(s[r], s[l]);
            }
            else {
                ans.push_back(r-1);
                ans.push_back(l+1);
                c = s[l+1];
                swap(s[r-1], s[l+1]);
            }
        }
    }
    sort(all(ans));
    cout << ans.size() << ' ';
    for (auto a : ans) cout << a + 1 << ' ';
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
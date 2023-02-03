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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<int> chk(26);
    for (int i=0; i<n; i++) {
        chk[a[i]-'a'] = 1;
    }
    vector<char> v;
    for (int i=0; i<26; i++) {
        if (chk[i]) v.push_back(i+'a');
    }
    if (v.size() <= k) {
        cout << (ll)n*(n+1)/2 << '\n';
        return;
    }
    vector<int> sel(v.size());

    for (int i=0; i<k; i++) sel[i] = 1;
    sort(sel.begin(), sel.end());
    ll ans = 0;
    do {
        for (int i=0; i<26; i++) chk[i] = 0;
        for (int i=0; i<(int)v.size(); i++) {
            if (sel[i]) chk[v[i]-'a'] = 1;
        }
        ll res = 0;
        ll cnt = 0;
        for (int i=0; i<=n; i++) {
            if (i == n || (a[i] != b[i] && chk[a[i]-'a'] == 0)) {
                res += cnt*(cnt+1)/2;
                cnt = 0;
            }
            else cnt++;
        }
        ans = max(ans, res);
    } while (next_permutation(sel.begin(), sel.end()));
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
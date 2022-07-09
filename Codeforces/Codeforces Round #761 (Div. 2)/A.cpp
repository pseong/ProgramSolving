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

void solve() {
    string s, t;
    cin >> s >> t;
    srt(s);
    if (t == "abc") {
        int cnt[26]{ 0 };
        for (int i=0; i<(int)s.size(); i++) {
            cnt[s[i]-'a']++;
        }
        if (cnt[0] && cnt[1] && cnt[2]) {
            cout << string(cnt[0], 'a');
            cout << string(cnt[2], 'c');
            cout << string(cnt[1], 'b');
            for (int i=3; i<26; i++) {
                cout << string(cnt[i], 'a'+i);
            }
            cout << '\n';
        }
        else {
            cout << s << '\n';
        }
    }
    else {
        cout << s << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
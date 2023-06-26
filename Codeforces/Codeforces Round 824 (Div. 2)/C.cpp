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
    vector<int> nxt(26, -1), chk(26);
    for (int i=0; i<n; i++) {
        if (nxt[s[i]-'a'] != -1) continue;
        for (int j=0; j<26; j++) {
            if (j == s[i]-'a') continue;
            if (chk[j]) continue;
            int cnt = 0;
            for (int i=0; i<26; i++) if (chk[i]) cnt++;
            if (cnt == 25) {
                nxt[s[i]-'a'] = j;
                chk[j] = 1;
                break;
            }
            bool ok = false;
            int g = j;
            while (nxt[g] != -1) g = nxt[g];
            if (g == s[i]-'a') continue;
            nxt[s[i]-'a'] = j;
            chk[j] = 1;
            break;
        }
    }
    for (int i=0; i<n; i++) s[i] = nxt[s[i]-'a'] + 'a';
    cout << s << '\n';
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
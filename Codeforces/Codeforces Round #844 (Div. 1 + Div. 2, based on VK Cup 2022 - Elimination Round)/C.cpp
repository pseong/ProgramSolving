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
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i=0; i<n; i++) {
        cnt[s[i]-'a']++;
    }
    vector<pi> v;
    for (int i=0; i<26; i++) {
        v.push_back({cnt[i], i});
    }
    sort(v.rbegin(), v.rend());
    int ans = 1e9;
    string ans2 = "";
    for (int i=1; i<=26; i++) {
        if (n % i == 0) {
            int cnt = n / i;
            int a = 0;
            int res = 0;
            vector<int> chk(26), need(26);
            for (int j=i; j<26; j++) {
                res += v[j].first;
            }
            for (int j=0; j<i; j++) {
                chk[v[j].second] = 1;
                if (v[j].first > cnt) {
                    chk[v[j].second] = 1;
                    need[v[j].second] = cnt - v[j].first;
                    res += v[j].first - cnt;
                }
                else if (v[j].first < cnt) {
                    chk[v[j].second] = 1;
                    need[v[j].second] = cnt - v[j].first;
                }
            }
            if (res < ans) {
                ans = res;
                string t = s;
                for (int i=0; i<n; i++) {
                    if (chk[t[i]-'a']) {
                        if (need[t[i]-'a'] < 0) {
                            for (int j=0; j<26; j++) {
                                if (need[j] > 0) {
                                    need[j]--;
                                    need[t[i]-'a']++;
                                    t[i] = j + 'a';
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        for (int j=0; j<26; j++) {
                            if (need[j] > 0) {
                                need[j]--;
                                t[i] = j + 'a';
                                break;
                            }
                        }
                    }
                }
                ans2 = t;
            }
        }
    }
    cout << ans << '\n' << ans2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        for (int k=0; k<n; k=+) {}
                    }
                }
            }
        }
    }
}
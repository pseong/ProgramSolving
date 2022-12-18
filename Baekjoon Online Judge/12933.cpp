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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    vector<int> cnt(5);
    int ans = 0;
    if (s.size() % 5 != 0) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == 'q') cnt[0]++;
        else if (s[i] == 'u') cnt[1]++;
        else if (s[i] == 'a') cnt[2]++;
        else if (s[i] == 'c') cnt[3]++;
        else if (s[i] == 'k') cnt[4]++;
        if (cnt[0] < cnt[1] || cnt[1] < cnt[2] || cnt[2] < cnt[3] || cnt[3] < cnt[4]) {
            cout << -1 << '\n';
            return 0;
        }
        int mn = *min_element(cnt.begin(), cnt.end());
        for (int i=0; i<5; i++) {
            cnt[i] -= mn;
        }
        ans = max(ans, cnt[0]);
    }
    if (cnt[0] || cnt[1] || cnt[2] || cnt[3] || cnt[4]) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
}
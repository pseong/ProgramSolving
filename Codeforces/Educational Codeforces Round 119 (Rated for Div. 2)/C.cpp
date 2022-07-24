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

    int T; cin >> T;
    for (int TT=1; TT<=T; TT++) {
        ll n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;

        ll now = 0;
        string ans;
        x--;
        for (int i=(int) s.size()-1; i>=0; i--) {
            if (i == 0 || s[i] == 'a') {
                if (s[i] == '*') now += k;
                if (now > 0) {
                    ans.append(x % (now+1), 'b');
                    x /= now+1;
                    now = 0;
                }
                if (s[i] == 'a') ans.push_back('a');
            }
            else now += k;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
        g:
        continue;
    }
}
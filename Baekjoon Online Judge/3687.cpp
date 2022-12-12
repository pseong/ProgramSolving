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

string dp[110];
vector<string> v{"", "", "1", "7", "4", "2", "0", "8"};
string inf = "999999999999999";

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = "";
    for (int i=1; i<=100; i++) {
        dp[i] = inf;
    }
    for (int i=2; i<=100; i++) {
        for (int j=2; j<=7; j++) {
            if (i-j < 0) continue;
            string a = dp[i-j] + v[j];
            string b = v[j] + dp[i-j];
            if (j == 6) {
                a = dp[i-j] + "0";
                if (stoll(a) == 0) a = inf;
                b = "6" + dp[i-j];
            }
            dp[i] = to_string(min({stoll(dp[i]), stoll(a), stoll(b)}));
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << ' ';
        if (n % 2 == 1) cout << "7", n -= 3;
        cout << string(n / 2, '1') << '\n';
    }
}
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
    string s;
    cin >> s;
    int n = s.size();
    for (int i=n-2; i>=0; i--) {
        int sum = s[i] + s[i+1] - 2*'0';
        if (sum >= 10) {
            s[i] = sum/10+'0';
            s[i+1] = sum%10+'0';
            cout << s << '\n';
            return;
        }
    }
    s[1] += s[0]-'0';
    s.erase(s.begin());
    cout << s << '\n';
    return;
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
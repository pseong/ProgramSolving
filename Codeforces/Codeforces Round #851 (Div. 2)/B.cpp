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
    int x = n/2;
    int y = n-x;
    if (n%2 == 0) cout << x << ' ' << y << '\n';
    else {
        int go = y;
        int cnt = 0;
        while (go%10 == 0) {
            cnt++;
            go /= 10;
        }
        for (int i=0; i<cnt; i++) {
            x /= 10;
            y /= 10;
        }
        string X = to_string(x);
        string Y = to_string(y);
        int q[] {5, 4};
        int s = 0;
        for (int i=0; i<cnt; i++) {
            X.push_back(q[s] + '0');
            s ^= 1;
        }
        s = 1;
        for (int i=0; i<cnt; i++) {
            Y.push_back(q[s] + '0');
            s ^= 1;
        }
        cout << stoi(X) << ' ' << stoi(Y) << '\n';
    }
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
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

    int n;
    cin >> n;
    vector<ti> v(n);
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, b, c};
    }
    int ans = 0;
    for (int x=0; x<1000; x++) {
        bool ok = true;
        for (int i=0; i<n; i++) {
            auto [y, s, b] = v[i];
            int S = 0, B = 0;
            string X = to_string(x);
            string Y = to_string(y);
            while (X.size() < 3) X.insert(X.begin(), '0');
            while (Y.size() < 3) Y.insert(Y.begin(), '0');
            if (X[0] == X[1] || X[1] == X[2] || X[0] == X[2]) ok = false;
            for (int a=0; a<3; a++) {
                if (X[a] == '0') ok = false;
                for (int b=0; b<3; b++) {
                    if (X[a] == Y[b]) {
                        if (a == b) S++;
                        else B++;
                    }
                }
            }
            if (S != s || B != b) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
}
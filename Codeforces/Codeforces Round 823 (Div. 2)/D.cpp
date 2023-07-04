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
    string a, b;
    cin >> a >> b;
    map<pair<char, char>, int> mp;
    for (int i=0; i<n; i++) {
        char c1 = a[i];
        char c2 = b[n-1-i];
        if (c1 > c2) swap(c1, c2);
        mp[{c1, c2}]++;
    }
    if (n%2) {
        int left = 1;
        for (auto [p, cnt] : mp) {
            if (p.first == p.second) {
                if (cnt%2) {
                    if (left) left--;
                    else {
                        no();
                        return;
                    }
                }
            }
            else {
                if (cnt%2) {
                    no();
                    return;
                }
            }
        }
    }
    else {
        for (auto [p, cnt] : mp) {
            if (cnt%2) {
                no();
                return;
            }
        }
    }
    yes();
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
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

    int n, m;
    cin >> n >> m;
    map<string, set<string>> t;
    map<string, string> w;
    for (int i=0; i<n; i++) {
        string title;
        cin >> title;
        int cnt;
        cin >> cnt;
        while (cnt--) {
            string s;
            cin >> s;
            t[title].insert(s);
            w[s] = title;
        }
    }

    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;
        if (x == 0) {
            for (auto& at : t[s]) {
                cout << at << '\n';
            }
        }
        else {
            cout << w[s] << '\n';
        }
    }
}
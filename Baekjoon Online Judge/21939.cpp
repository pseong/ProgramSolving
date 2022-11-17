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
    
    multiset<pi> ms;
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p, l;
        cin >> p >> l;
            mp.insert({p, l});
            ms.insert({l, p});
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int a, b;
            cin >> a >> b;
            mp.insert({a, b});
            ms.insert({b, a});
        }
        if (s == "recommend") {
            int a;
            cin >> a;
            if (a == 1) {
                cout << ms.rbegin()->second << '\n';
            }
            if (a == -1) {
                cout << ms.begin()->second << '\n';
            }
        }
        if (s == "solved") {
            int a;
            cin >> a;
            ms.erase({mp[a], a});
            mp.erase(a);
        }
    }
}
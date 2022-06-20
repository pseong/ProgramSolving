#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n; cin >> n;
    map<int, vector<int>> mp;
    for (int y=3; y<=n; y++) {
        cout << "? " << 1 << ' ' << y << endl;
        int r;
        cin >> r;
        cout << "? " << 2 << ' ' << y << endl;
        int r2;
        cin >> r2;
        
        mp[r+r2].push_back(y);
    }
    auto& [r, v] = *mp.begin();
    if (r == 3) {
        if (v.size() == 2) {
            cout << "? " << v[0] << ' ' << v[1] << endl;
            int r;
            cin >> r;
            if (r == 1) {
                cout << "! 3" << endl;
            }
            else {
                cout << "! 1" << endl;
            }
        }
        else {
            cout << "! 1" << endl;
        }
    }
    else {
        cout << "! " << r << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
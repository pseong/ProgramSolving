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
    n = 1 << n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        v[i] = i + 1;
    }
    while (v.size() >= 4) {
        vector<int> v2;
        for (int i=0; i<(int)v.size(); i+=4) {
            cout << "? " << v[i] << ' ' << v[i+2] << endl;
            int r;
            cin >> r;
            if (r == 0) {
                cout << "? " << v[i+1] << ' ' << v[i+3] << endl;
                cin >> r;
                if (r == 1) v2.push_back(v[i+1]);
                else v2.push_back(v[i+3]);
            }
            else if (r == 1) {
                cout << "? " << v[i] << ' ' << v[i+3] << endl;
                cin >> r;
                if (r == 1) v2.push_back(v[i]);
                else v2.push_back(v[i+3]);
            }
            else if (r == 2) {
                cout << "? " << v[i+1] << ' ' << v[i+2] << endl;
                cin >> r;
                if (r == 1) v2.push_back(v[i+1]);
                else v2.push_back(v[i+2]);
            }
        }
        v = v2;
    }
    if (v.size() == 2) {
        cout << "? " << v[0] << ' ' << v[1] << endl;
        int r;
        cin >> r;
        if (r == 1) v = { v[0] };
        else v = { v[1] };
    }
    cout << "! " << v[0] << endl;
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
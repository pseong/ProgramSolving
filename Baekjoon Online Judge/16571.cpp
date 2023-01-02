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

int valid(vector<vector<int>> v) {
    for (int i=0; i<3; i++) {
        if (v[i][0] != 0 && v[i][0] == v[i][1] && v[i][1] == v[i][2]) return v[i][0];
    }
    for (int j=0; j<3; j++) {
        if (v[0][j] != 0 && v[0][j] == v[1][j] && v[1][j] == v[2][j]) return v[0][j];
    }
    if (v[0][0] != 0 && v[0][0] == v[1][1] && v[1][1] == v[2][2]) return v[0][0];
    if (v[0][2] != 0 && v[0][2] == v[1][1] && v[1][1] == v[2][0]) return v[0][2];
    bool ok = true;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (v[i][j] == 0) ok = false;
        }
    }
    if (ok) return 3;
    return 0;
}

int chk(vector<vector<int>> v) {
    vector<int> cnt(3);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cnt[v[i][j]]++;
        }
    }
    int now = 2;
    int ret = 0;
    if (cnt[1] == cnt[2]) now = 1;
    int val = valid(v);
    if (val != 0) {
        if (val == 3) return 1;
        else if (val == now) return 2;
        else return 0;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (v[i][j] == 0) {
                v[i][j] = now;
                ret = max(ret, 2 - chk(v));
                v[i][j] = 0;
            }
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> v(3, vector<int>(3));
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }
    int ans = chk(v);
    if (ans == 0) cout << "L\n";
    else if (ans == 1) cout << "D\n";
    else if (ans == 2) cout << "W\n";
}
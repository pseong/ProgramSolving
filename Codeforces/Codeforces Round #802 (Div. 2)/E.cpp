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

vector<vector<int>> v;
int n, m;

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int dx[] {-1, 0, 0, 1, 0};
int dy[] {0, -1, 1, 0, 0};

bool good(int x, int y) {
    if (v[x][y] == 1) return true;
    for (int d=0; d<4; d++) {
        int i=x+dx[d];
        int j=y+dy[d];
        if (!valid(i, j)) continue;
        if (v[i][j] < v[x][y]) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    v.resize(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    vector<pi> error;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (v[i][j] == 1) continue;
            if (!good(i, j)) error.push_back({i, j});
        }
    }

    if (error.empty()) {
        cout << 0;
        return;
    }

    if (error.size() > 8) {
        cout << 2;
        return;
    }

    set<tuple<int, int, int, int>> st;
    for (int d=0; d<5; d++) {
        int x=error[0].first + dx[d];
        int y=error[0].second + dy[d];
        if (!valid(x, y)) continue;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                swap(v[i][j], v[x][y]);
                bool ok = true;
                for (int D=0; D<5; D++) {
                    int X = i+dx[D];
                    int Y = j+dy[D];
                    if (!valid(X, Y)) continue;
                    if (!good(X, Y)) ok = false;
                }
                for (int D=0; D<5; D++) {
                    int X = x+dx[D];
                    int Y = y+dy[D];
                    if (!valid(X, Y)) continue;
                    if (!good(X, Y)) ok = false;
                }
                for (auto at : error) {
                    if (!good(at.first, at.second)) ok = false;
                }
                if (ok) {
                    st.insert({i+1, j+1, x+1, y+1});
                    st.insert({x+1, y+1, i+1, j+1});
                }
                swap(v[i][j], v[x][y]);
            }
        }
    }
    if (st.size()) {
        cout << 1 << ' ';
        cout << st.size()/2;
        return;
    }
    cout << 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
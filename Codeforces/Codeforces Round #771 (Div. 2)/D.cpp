#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

int v[1010][1010];
int dx[] { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, m;
bool valid(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    queue<ti> q;
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (v[i][j] == v[i+1][j] &&
                v[i][j] == v[i][j+1] &&
                v[i][j] == v[i+1][j+1]) {
                q.push({i, j, v[i][j]});
                v[i][j] = 0;
                v[i+1][j] = 0;
                v[i][j+1] = 0;
                v[i+1][j+1] = 0;
            }
        }
    }

    vector<ti> ans;
    while (q.size()) {
        ans.push_back(q.front());
        auto [x, y, c] = q.front();
        q.pop();
        for (int d=0; d<8; d++) {
            int i=x+dx[d];
            int j=y+dy[d];
            if (!valid(i, j) || !valid(i+1, j) || !valid(i, j+1) || !valid(i+1, j+1)) {
                continue;
            }
            set<int> st;
            if (v[i][j]) st.insert(v[i][j]);
            if (v[i+1][j]) st.insert(v[i+1][j]);
            if (v[i][j+1]) st.insert(v[i][j+1]);
            if (v[i+1][j+1]) st.insert(v[i+1][j+1]);
            if (st.size() == 1) {
                v[i][j] = 0;
                v[i+1][j] = 0;
                v[i][j+1] = 0;
                v[i+1][j+1] = 0;
                q.push({i, j, *st.begin()});
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j]) {
                cout << -1;
                return;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto [x, y, c] : ans) {
        cout << x << ' ' << y << ' ' << c << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
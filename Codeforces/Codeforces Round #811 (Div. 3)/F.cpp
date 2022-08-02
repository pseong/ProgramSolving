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

int now;
vector<pi> edges;

void addEdge(int start, int end, int len) {
    if (len == 1) {
        edges.push_back({start, end});
        return;
    }
    int root = start;
    for (int i=0; i<len-1; i++) {
        edges.push_back({root, now});
        root = now;
        now++;
    }
    edges.push_back({root, end});
}

void solve(int CASE) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    now = 4;
    edges.clear();
    if (a == b + c) {
        addEdge(1, 3, c);
        addEdge(3, 2, b);
        for (int i=now; i<=n; i++) {
            edges.push_back({1, i});
        }
    }
    else if (b == a + c) {
        addEdge(1, 2, a);
        addEdge(1, 3, c);
        for (int i=now; i<=n; i++) {
            edges.push_back({1, i});
        }
    }
    else if (c == a + b) {
        addEdge(1, 2, a);
        addEdge(2, 3, b);
        for (int i=now; i<=n; i++) {
            edges.push_back({1, i});
        }
    }
    else if ((a+b+c)%2 == 0 && a + b > c && a + c > b && c + b > a && (a+b+c)/2 + 1 <= n) {
        now = 5;
        addEdge(4, 1, (a + c - b) / 2);
        addEdge(4, 2, (a + b - c) / 2);
        addEdge(4, 3, (b + c - a) / 2);
        for (int i=now; i<=n; i++) {
            edges.push_back({4, i});
        }
    }
    else {
        no();
        return;
    }
    yes();
    for (auto [a, b] : edges) {
        cout << a << ' ' << b << '\n';
    }
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
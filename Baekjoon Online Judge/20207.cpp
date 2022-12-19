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

int m[1010][400];

struct Node {
    int s, e;
    bool operator<(Node& r) {
        if (s != r.s) return s < r.s;
        return e > r.e;
    }
};

bool ok(int x, Node node) {
    for (int i=node.s; i<=node.e; i++) {
        if (m[x][i]) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Node> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].s >> v[i].e;
    }
    sort(v.begin(), v.end());
    int mxj = 0;
    int l = -1;
    int r = -1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=1000; j++) {
            if (ok(j, v[i])) {
                for (int k=v[i].s; k<=v[i].e; k++) {
                    m[j][k] = 1;
                }
                if (v[i].s > r + 1) {
                    ans += (r - l + 1) * mxj;
                    l = v[i].s;
                    r = v[i].e;
                    mxj = j;
                }
                r = max(r, v[i].e);
                mxj = max(mxj, j);
                break;
            }
        }
    }
    ans += (r - l + 1) * mxj;
    cout << ans << '\n';
}
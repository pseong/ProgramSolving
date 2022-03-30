#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int mod = 998244353;
vector<int> factors[202020];
vector<tuple<int, int, int>> adj[202020];
int d[202020];
ll f[202020], wf[202020];

ll powll(ll a, ll b) {
    if (b == 1) return a;
    ll two = powll(a, b/2);
    two %= mod;
    two *= two;
    two %= mod;
    if (b & 1) return (two * a) % mod;
    else return two;
}

void dfs(int node, int par) {
    for (auto au : adj[node]) {
        int to, x, y;
        tie(to, x, y) = au;
        if (to == par) continue;
        for (int a : factors[y]) f[a]--;
        for (int a : factors[x]) {
            f[a]++;
            wf[a] = max(wf[a], f[a]);
        }
        dfs(to, node);
        for (int a : factors[y]) f[a]++;
        for (int a : factors[x]) f[a]--;
    }
}

ll ans = 0;
void dfs2(int node, int par, ll p) {
    ans += p;
    ans %= mod;
    for (auto au : adj[node]) {
        int to, x, y;
        tie(to, x, y) = au;
        if (to == par) continue;
        ll tmp = p;
        tmp *= y;
        tmp %= mod;
        tmp *= powll(x, mod-2);
        tmp %= mod;
        dfs2(to, node, tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=200005; i>=2; i--) {
        for (int j=i; j<=200005; j+=i) {
            d[j] = i;
        }
    }

    for (int i=1; i<=200005; i++) {
        for (int j=i; j!=1; j/=d[j]) {
            factors[i].push_back(d[j]);
        }
    }

    int T; cin >> T;
    while (T--) {
        memset(f, 0, sizeof f);
        memset(wf, 0, sizeof wf);
        int n;
        cin >> n;
        set<int> distinct_primes;
        for (int k=0; k<n-1; k++) {
            int i, j, x, y;
            cin >> i >> j >> x >> y;
            int a = __gcd(x, y);
            x /= a;
            y /= a;
            adj[i].push_back({j, x, y});
            adj[j].push_back({i, y, x});
            for (int z : factors[x])
                distinct_primes.insert(z);
            for (int z : factors[y])
                distinct_primes.insert(z);
        }

        dfs(1, 0);

        ll p = 1;
        for (int a : distinct_primes) {
            for (int i=0; i<wf[a]; i++) {
                p *= a; p %= mod;
            }
        }

        ans = 0;
        dfs2(1, 0, p);

        cout << ans % mod << '\n';
        for (int i=1; i<=n; i++) {
            adj[i].clear();
        }
    }
}
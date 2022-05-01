#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    string init;
    cin >> n >> k >> init;
    ll h = 0, t = 0;
    for (ll i=0; i<init.size(); i++) {
        if (init[i] == 'H') h++;
        else t++;
    }

    map<pll, ll> dist;
    queue<pll> q;
    ll cnt = 0;
    dist[{h, t}] = cnt;
    q.push({h, t});
    while (q.size()) {
        ll loop = q.size();
        cnt++;
        while (loop--) {
            ll H, T;
            tie(H, T) = q.front(); q.pop();
            for (ll i=0; i<=k; i++) {
                if (H-i < 0 || T-(k-i) < 0) continue;
                if (dist.find({H-i+k-i, T+i-k+i}) != dist.end()) continue;
                dist[{H-i+k-i, T+i-k+i}] = cnt;
                q.push({H-i+k-i, T+i-k+i});
            }
        }
    }

    if (dist.find({0, n}) == dist.end()) cout << -1;
    else cout << dist[{0, n}];
}
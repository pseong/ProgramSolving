#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int n, m, k;
pii edge[202020];
vector<int> adj[101010];
int color[101010]{ 0 };
int erase[202020]{ 0 };
int brk[202020];
int sec1, sec2;

bool bi(int mid) {
    for (int i=0; i<101010; i++) adj[i].clear();
    memset(color, 0, sizeof color);
    memset(erase, 0, sizeof erase);
    sec1 = sec2 = 0;
    for (int i=1; i<=mid; i++) {
        erase[brk[i]] = 1;
    }
    for (int i=1; i<=m; i++) {
        if (erase[i]) continue;
        int a, b;
        tie(a, b) = edge[i];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int bipar = 1;
    queue<pii> q;
    q.push({1, 1});
    color[1] = 1;
    while (q.size()) {
        int x, col;
        tie(x, col) = q.front(); q.pop();
        for (int y : adj[x]) {
            if (color[y] == 0) {
                color[y] = col^1^2;
                q.push({y, color[y]});
            }
            else {
                if (color[y] != (col^1^2)) return false;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        if (color[i] == 1) sec1++;
        else if (color[i] == 2) sec2++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i=1; i<=m; i++) {
        cin >> edge[i].first >> edge[i].second;
    }
    for (int i=1; i<=k; i++) {
        cin >> brk[i];
    }

    int l = 0;
    int r = k;
    int ans = -1;
    int ans_sec1 = 0;
    int ans_sec2 = 0;
    while (l <= r) {
        int mid = (l+r)/2;
        if (bi(mid)) {
            ans = mid;
            r = mid - 1;
            ans_sec1 = sec1;
            ans_sec2 = sec2;
        }
        else {
            l = mid + 1;
        }
    }
    if (ans_sec1 > ans_sec2) swap(ans_sec1, ans_sec2);
    cout << ans << '\n';

    if (ans != -1)
    cout << ans_sec1 << ' ' << ans_sec2;
}
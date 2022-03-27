#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
map<pii, int> mp;
pii an[202020];
pii ans[202020];
bool chk[202020];
queue<int> q;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i].first >> an[i].second;
        mp[an[i]] = i;
    }

    for (int i=1; i<=n; i++) {
        int x, y; tie(x, y) = an[i];
        for (int d = 0; d < 4; d++) {
            int a = x+dx[d];
            int b = y+dy[d];
            if (mp[{a, b}]) continue;
            chk[i] = true;
            ans[i] = {a, b};
            q.push(i);
        }
    }

    while (q.size()) {
        int i = q.front(); q.pop();
        int x, y; tie(x, y) = an[i];
        for (int d=0; d<4; d++) {
            int t = mp[{x+dx[d], y+dy[d]}];
            if (!t || chk[t]) continue;
            chk[t] = true;
            ans[t] = ans[i];
            q.push(t);
        }
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
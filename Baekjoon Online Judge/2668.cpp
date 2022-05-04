#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int in[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        in[v[i]]++;
    }

    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (q.size()) {
        int a = q.front(); q.pop();
        in[v[a]]--;
        if (in[v[a]] == 0) q.push(v[a]);
    }

    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (in[i] > 0 ) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    for (int i=1; i<=n; i++) {
        if (in[i] > 0 ) {
            cout << i << '\n';
        }
    }
}
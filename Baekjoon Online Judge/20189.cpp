#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

vector<int> v[2020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    bool allone = true;
    for (int i=0; i<k; i++) {
        if (v[1][i] != 1) allone = false;
    }
    ll dist = 0;
    if (allone) dist += n;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<k; j++) {
            if (v[i][j] >= i) {
                dist += v[i][j]-i;
            }
            else {
                dist += n-i+v[i][j];
            }
        }
    }
    assert(dist%n == 0);
    if (dist/n > q) {
        cout << 0;
    }
    else {
        cout << 1;
    }
}
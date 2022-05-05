#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;

struct dsu {
    vector<int> parent;
    dsu(int n) {
        parent.resize(n+1);
        for (int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }
    int leader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = leader(parent[i]);
    }
    int merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x > y) swap(x, y);
        return parent[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<ti> v;
    for (int i=1; i<=n; i++) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        v.push_back({x1, x2, i});
    }
    sort(v.begin(), v.end());

    dsu ds(100000);
    int start = -1;
    int end = -1;
    for (int i=0; i<n; i++) {
        int a, b, c;
        tie(a, b, c) = v[i];
        if (end < a) {
            start = a;
            end = b;
        }
        else {
            end = max(end, b);
            ds.merge(get<2>(v[i-1]), c);
        }
    }
    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ds.same(a, b) << '\n';
    }
}
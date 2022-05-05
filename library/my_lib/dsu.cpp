#include <bits/stdc++.h>
using namespace std;

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
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll inf = 1000000000000000000;

struct Seg {
    struct Node {
        ll l, r, a, sum, have;
    };
    Node tree[20000];
    void init() {
        for (int i=0; i<20000; i++) {
            tree[i].a = 0;
            tree[i].l = 0;
            tree[i].r = 0;
            tree[i].sum = 0;
            tree[i].have = 0;
        }
    }
    Node merge(Node l, Node r) {
        if (l.have == 0 && r.have == 0) {
            return Node {
                0,
                0,
                0,
                0,
                0,
            };
        }
        if (l.have == 0) return r;
        if (r.have == 0) return l;
        return Node {
            max(l.l, l.sum + r.l),
            max(r.r, r.sum + l.r),
            max({l.a, r.a, l.r + r.l}),
            l.sum + r.sum,
            l.have + r.have,
        };
    }
    Node add(int n, int s, int e, int x, ll y) {
        if (x < s || x > e) return tree[n];
        else if (s == e) {
            tree[n].l += y;
            tree[n].r += y;
            tree[n].a += y;
            tree[n].sum += y;
            tree[n].have = 1;
            return tree[n];
        }
        int mid = (s+e)/2;
        Node l = add(n*2, s, mid, x, y);
        Node r = add(n*2+1, mid+1, e, x, y);
        return tree[n] = merge(l, r);
    }
    Node query() {
        return tree[1];
    }
} seg;

struct Event {
    ll x, y, w;
};
bool operator< (const Event& e1, const Event& e2) {
    if (e1.x == e2.x) return e1.y < e2.y;
    else return e1.x < e2.x;
}

vector<vector<Event>> events;
ll ans = -inf;
int n, sz;

void cal(int i) {
    seg.init();
    for (int j=i; j<events.size(); j++) {
        for (Event& e : events[j]) {
            seg.add(1, 1, sz, e.y, e.w);
        }
        ll aa = seg.query().a;
        ans = max(ans, aa);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<ll> ys;
    vector<Event> es;
    for (int i=0; i<n; i++) {
        Event e;
        cin >> e.x >> e.y >> e.w;
        es.push_back(e);
        ys.push_back(e.y);
    }
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    sz = ys.size();
    for (int i=0; i<n; i++) {
        es[i].y = lower_bound(ys.begin(), ys.end(), es[i].y) - ys.begin() + 1;
    }
    sort(es.begin(), es.end());
    int i = 0;
    while (i < es.size()) {
        events.push_back({});
        events.back().push_back(es[i]);
        i++;
        while (i < es.size() && es[i].x == es[i-1].x) {
            events.back().push_back(es[i]);
            i++;
        }
    }
    for (int i=0; i<n; i++) cal(i);
    cout << ans;
}
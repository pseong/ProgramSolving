#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int inf = 1e9+10;
int n;
int a[101010];
vector<int> comp;
vector<int> g[101010];

struct Node{
    Node* l;
    Node* r;
    Node* p;
    ll v, sz, sum, mx, mn;
    bool dummy, flip;

    Node(ll _v, Node *p) : v(_v), p(p) {
        l = r = nullptr;
        sum = mx = mn = _v;
        sz = 1;
        dummy = 0;
        flip = 0;
    }
    Node(int _v) : Node(_v, nullptr) {}
    Node() : Node(0) {}
    ~Node() {
        if (l) delete l;
        if (r) delete r;
    }
};

struct SplayTree {
    Node *root;
    Node *ptr[101010];

    SplayTree() : root() {
        memset(ptr, 0, sizeof ptr);
    }
    ~SplayTree() {
        if (root) delete root;
    }

    void init() {
        if (root) delete root;
        ptr[0] = root = new Node(-inf);
        auto now = root;
        for(int i=1; i<=n; i++) {
            ptr[a[i]] = now->r = new Node(a[i], now);
            now = now->r;
        }
        ptr[n+1] = now->r = new Node(inf, now);
        root->dummy = now->r->dummy = 1;
        for(int i=n+1; i>=0; i--) {
            update(ptr[i]);
        }
    }

    void rotate(Node *x) {
        auto p = x->p;
        Node *y;
        push(p); push(x);
        if (x == p->l) p->l = y = x->r, x->r = p;
        else p->r = y = x->l, x->l = p;
        x->p = p->p; p->p = x;
        if (y) y->p = p;
        if (x->p) {
            if (p == x->p->l) x->p->l = x;
            else x->p->r = x;
        }
        else root = x;
        update(p); update(x);
    }

    void splay(Node *x, Node *g = nullptr) {
        Node *y;
        while (x->p != g) {
            Node *p = x->p;
            if (p->p == g) { rotate(x); break; }
            auto pp = p->p;
            if ((p->l == x) == (pp->l == p)) rotate(p);
            else rotate(x);
            rotate(x);
        }
        if (!g) root = x;
    }

    void update(Node *x) {
        x->sz = 1;
        if (x->l) x->sz += x->l->sz;
        if (x->r) x->sz += x->r->sz;
    }

    void push(Node *x) {
        if (!x->flip) return;
        swap(x->l, x->r);
        if (x->l) x->l->flip = !x->l->flip;
        if (x->r) x->r->flip = !x->r->flip;
        x->flip = 0;
    }

    Node* gather(int s, int e) {
        kth(e+1);
        auto tmp = root;
        kth(s-1);
        splay(tmp, root);
        return root->r->l;
    }

    void flip(int s, int e) {
        Node *x = gather(s, e);
        x->flip = !x->flip;
    }

    int getidx(int k) {
        splay(ptr[k]);
        return root->l->sz;
    }

    void kth(int k) {
        auto now = root;
        push(now);
        while (true) {
            while (now->l && now->l->sz > k) now = now->l, push(now);
            if (now->l) k -= now->l->sz;
            if (!k) break;
            k--;
            now = now->r;
            push(now);
        }
        splay(now);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> n; if (!n) return 0;
        comp.clear(); comp.reserve(n);
        for (int i=1; i<=n; i++) cin >> a[i], comp.push_back(a[i]);
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        for (int i=0; i<comp.size(); i++) g[i].clear();
        for (int i=1; i<=n; i++) {
            a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
            g[a[i]].push_back(i);
        }
        int pv = 0;
        for (int i=0; i<comp.size(); i++) {
            for(auto j : g[i]) a[j] = ++pv;
        }
        SplayTree tree;
        tree.init();
        for (int i=1; i<=n; i++) {
            int t = tree.getidx(i);
            cout << t << " ";
            tree.flip(i, t);
        }
        cout << "\n";
    }
}
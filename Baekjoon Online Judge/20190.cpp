#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int x = 1000000;

struct Lazyseg {
	struct Node {
		ll mn, sum;
	} tr[4040404];
	ll lazy[4040404];

	void init() {
		memset(lazy, 0, sizeof lazy);
		memset(tr, 0, sizeof tr);
	}

	Node merge(Node a, Node b) {
		return { min(a.mn, b.mn), a.sum + b.sum };
	}

	void propagation(int n, int s, int e) {
		if (lazy[n]) {
			tr[n].mn += lazy[n];
			tr[n].sum += ((ll)e-s+1)*lazy[n];
			if (s != e) {
				lazy[n*2] += lazy[n];
				lazy[n*2+1] += lazy[n];
			}
			lazy[n] = 0;
		}
	}

	void update_range(int n, int s, int e, int l, int r, ll x) {
		propagation(n, s, e);
		if (r < s || e < l) return;
		if (l <= s && e <= r) {
			lazy[n] += x;
			propagation(n, s, e);
			return;
		}
		int mid = (s+e)/2;
		update_range(n*2, s, mid, l, r, x);
		update_range(n*2+1, mid+1, e, l, r, x);
		tr[n] = merge(tr[n*2], tr[n*2+1]);
	}

	Node query(int n, int s, int e, int l, int r) {
		propagation(n, s, e);
		if (r < s || e < l) return {0, 0};
		if (l <= s && e <= r) return tr[n];
		int mid = (s+e)/2;
		Node a = query(n*2, s, mid, l, r);
		Node b = query(n*2+1, mid+1, e, l, r);
		return merge(a, b);
	}

} seg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n;
    cin >> n;
    vector<int> an(n);
    ll all = 0;
    for (int i=0; i<n; i++) {
        cin >> an[i];
        if (an[i]+1 <= x) all += seg.query(1, 1, x, an[i]+1, x).sum;
        seg.update_range(1, 1, x, an[i], an[i], 1);
    }
	
	seg.init();
	for (int i=0; i<n; i++) {
		if (an[i]+1 <= x) seg.update_range(1, 1, x, an[i]+1, x, 1);
	}

	for (int i=0; i<n; i++) {
		if (an[i]+1 <= x) seg.update_range(1, 1, x, an[i]+1, x, -1);
		ll pre = seg.query(1, 1, x, an[i], an[i]).sum;
		ll post = seg.query(1, 1, x, 1, x).mn;
		cout << all - pre + post << ' ';
		if (an[i]-1 >= 1) seg.update_range(1, 1, x, 1, an[i]-1, 1);
	}
}
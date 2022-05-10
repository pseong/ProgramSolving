#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;

struct Lazyseg {
	//EDIT TYPE
	typedef long long _T;
	typedef long long _L;
    //
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T(*op)(_T, _T);
	_T t;
	Lazyseg(_T(*op)(_T, _T), int n, _T t) : op(op), n(n), t(t) {
		S.resize(4*n+10, 0);
		lazy.resize(4*n+10, 0);
	}
	void propagate(int node, int s, int e) {
		if (lazy[node] == 0) return;
        // EDIT HERE
        S[node] += ((_T)e-s+1)*lazy[node];
        if (s!=e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        //
		lazy[node] = 0;
	}
	_T query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
		if (e < l || r < s) return t;
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update_range(int node, int s, int e, int l, int r, _L x) {
        propagate(node, s, e);
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			// EDIT HERE
			lazy[node] += x;
            //
			propagate(node, s, e);
			return;
		}
		int mid = (s + e) / 2;
		update_range(node*2, s, mid, l, r, x);
		update_range(node*2+1, mid+1, e, l, r, x);
		S[node] = op(S[node*2], S[node*2+1]);
	}
	void update_range(int l, int r, _L x) {
		update_range(1, 1, n, l, r, x);
	}
};

bool cmp(pi a, pi b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

ll op(ll a, ll b) { return a+b; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Lazyseg seg(op, n, 0);
        vector<int> ynums;
        vector<pi> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i].first >> v[i].second;
            ynums.push_back(v[i].second);
        }
        sort(ynums.begin(), ynums.end());
        ynums.erase(unique(ynums.begin(), ynums.end()), ynums.end());
        map<int, int> ymp;
        for (int i=0; i<ynums.size(); i++) {
            ymp[ynums[i]] = i+1;
        }
        for (int i=0; i<n; i++) {
            v[i].second = ymp[v[i].second];
        }
        sort(v.begin(), v.end(), cmp);
        ll ans = 0;
        for (int i=0; i<n; i++) {
            int b = v[i].second;
            ans += seg.query(b, seg.n);
            seg.update_range(b, b, 1);
        }
        cout << ans << '\n';
    }
}
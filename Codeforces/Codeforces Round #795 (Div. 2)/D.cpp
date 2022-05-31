#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

struct Lazyseg {
	// EDIT TYPE
	typedef struct {
        long long sum, mx;
    } _T;
	typedef long long _L;
    //
	int n;
	vector<_T> S;
	vector<_L> lazy;
	_T op(_T a, _T b) {
        return {a.sum + b.sum, max(a.mx, b.mx)};
    }
	Lazyseg(int n, ll t) : n(n) {
		S.resize(4*n+10, {0, 0});
		lazy.resize(4*n+10, 0);
	}
	void propagate(int node, int s, int e) {
		if (lazy[node] == 0) return;
        // EDIT HERE
        S[node].sum += ((ll)e-s+1)*lazy[node];
        S[node].mx += lazy[node];
        if (s!=e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        //
		lazy[node] = 0;
	}
	_T query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
		if (e < l || r < s) return {0, -1000000000000000000};
		if (l <= s && e <= r) return S[node];
		int mid = (s+e)/2;
		return op(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
	}
	_T query(int l, int r) {
		return query(1, 1, n, l, r);
	}
	void update_range(int node, int s, int e, int l, int r, ll x) {
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
	void update_range(int l, int r, ll x) {
		update_range(1, 1, n, l, r, x);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n+1);
        Lazyseg segr(n, 0), segl(n, 0);
        for (int i=1; i<=n; i++) {
            cin >> v[i];
            segr.update_range(i, n, v[i]);
        }
        vector<int> l(n+1), r(n+1);

        vector<int> st;
        for (int i=1; i<=n; i++) {
            while (st.size() && v[st.back()] < v[i]) {
                r[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        for (int i=0; i<(int) st.size(); i++) {
            r[st[i]] = n+1;
        }
        st.clear();
        for (int i=n; i>=1; i--) {
            while (st.size() && v[st.back()] < v[i]) {
                l[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        for (int i=0; i<(int) st.size(); i++) {
            l[st[i]] = 0;
        }

        bool ok = true;
        for (int i=1; i<=n; i++) {
            segl.update_range(1, i-1, v[i-1]);
            segr.update_range(i, n, -v[i]);
            int left = l[i];
            int right = r[i];

            ll mxl = segl.query(left+1, i-1).mx;
            ll mxr = segr.query(i+1, right-1).mx;

            if (mxl > 0 || mxr > 0) {
                ok = false;
                break;
            }
        }

        if (!ok) cout << "NO\n";
        else cout << "YES\n";
    }
}
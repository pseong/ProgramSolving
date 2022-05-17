#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

struct BIT {
	int tree[101010];
	int cnt[101010];
	
	void add(int x) {
		if (cnt[x]) { cnt[x]++; return; }
		for (int i=x; i<=100000; i += i&-i) tree[i]++;
		cnt[x] = 1;
	}
	void sub(int x) {
		if (cnt[x] > 1) { cnt[x]--; return; }
		for (int i=x; i<=100000; i += i&-i) tree[i]--;
		cnt[x] = 0;
	}
	int get(int x) {
		int ret = 0;
		for (int i=x; i>=1; i -= i&-i) ret += tree[i];
		return ret;
	}
	int query(int l, int r) {
		return get(r) - get(l-1);
	}

} fwtx, fwty;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    while (q--) {
        int what; cin >> what;
        if (what == 1) {
            int x, y; cin >> x >> y;
            fwtx.add(x);
            fwty.add(y);
        }
        else if (what == 2) {
            int x, y; cin >> x >> y;
            fwtx.sub(x);
            fwty.sub(y);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int sx = fwtx.query(x1, x2);
            int sy = fwty.query(y1, y2);
            if (sx == x2-x1+1 || sy == y2-y1+1) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
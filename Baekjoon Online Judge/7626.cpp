#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<int> ys;
unordered_map<int, int> mp;

struct Seg {
	ll tree[303030*4], cnt[303030*4];
	ll query() {
		return tree[1];
	}
	void update_range(int n, int s, int e, int l, int r, ll x) {
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			cnt[n] += x;
			if (cnt[n] > 0) tree[n] = ys[e] - ys[s-1];
			else {
				tree[n] = 0;
				if (s != e) tree[n] = tree[n*2] + tree[n*2+1];
			}
			return;
		}
		int mid = (s+e)/2;
		update_range(n*2, s, mid, l, r, x);
		update_range(n*2+1, mid+1, e, l, r, x);
		if (cnt[n] > 0) tree[n] = ys[e] - ys[s-1];
		else tree[n] = tree[n*2] + tree[n*2+1];
	}
} seg;

struct Event {
    ll op, x, y1, y2;
};
vector<Event> events;

bool comp(Event e1, Event e2) {
    return e1.x < e2.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        events.push_back({1, a, c, d});
        events.push_back({0, b, c, d});
		ys.push_back(c);
		ys.push_back(d);
    }
	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	for (int i=0; i<ys.size(); i++) mp[ys[i]] = i+1;

    sort(events.begin(), events.end(), comp);
    ll prev = -1;
    ll ans = 0;
    for (Event e : events) {
		if (prev != -1) ans += (e.x-prev)*seg.query();
		prev = e.x;
		if (e.op == 1) {
			seg.update_range(1, 1, ys.size(), mp[e.y1], mp[e.y2]-1, 1);
		}
		else {
			seg.update_range(1, 1, ys.size(), mp[e.y1], mp[e.y2]-1, -1);
		}
    }
    cout << ans;
}
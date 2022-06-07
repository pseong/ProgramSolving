#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int an[1 << 17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
	while (T--) {
		int N, Q;
		cin >> N >> Q;
		for (int i = 1; i <= N; i++) cin >> an[i];
		int cv = an[1];
 
		set<pi> cur;
		cur.emplace(1, cv);
		for (int i = 2; i <= N; i++) {
			if (cv <= an[i]) continue;
			else {
				cv = an[i];
				cur.emplace(i, cv);
			}
		}
 
		while (Q--) {
			int k, d;
			cin >> k >> d;
			auto it = cur.lower_bound({k, 2e9});
			it--;
            int st, v;
            tie(st, v) = *it;
			an[k] -= d;
			if (v > an[k]) {
				if (st == k) cur.erase({k, 2e9});
				cur.emplace(k, an[k]);
				auto it2 = cur.find({k, an[k]});
				it2++;
				while (it2 != cur.end() && (*it2).second >= an[k]) {
					it2 = cur.erase(it2);
				}
			}
 
			cout << cur.size() << ' ';
		}
		cout << '\n';
	}
	return 0;
}
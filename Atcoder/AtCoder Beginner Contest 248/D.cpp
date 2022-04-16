#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> idx(n + 1);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		idx[a].push_back(i+1);
	}
	int q;
	cin >> q;
	while(q--) {
		int l, r, x;
		cin >> l >> r >> x;
		cout << upper_bound(idx[x].begin(), idx[x].end(), r) - lower_bound(idx[x].begin(), idx[x].end(), l) << '\n';
	}
}
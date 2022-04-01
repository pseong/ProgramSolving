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

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
		vector<int> S(4 * n);
		int pos = n*2;
		int sums[3]{ 0 };
		ll ans = 0;
		for (int i=0; i<(int)s.size(); i++) {
			S[pos]++;
			sums[pos % 3]++;
			if (s[i] == '+') {
				sums[pos % 3] -= S[pos];
				pos--;
			}
			else {
				pos++;
				sums[pos % 3] += S[pos];
			}
			ans += sums[pos % 3];
		}
		cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

ll n, k, val[4], idx[4];
vector<ll> v[4];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> val[0] >> val[1] >> val[2] >> val[3];

    for (ll i=0; i<n; i++) {
        char c;
        ll p;
        cin >> c >> p;
        for (ll i=0; i<4; i++) {
            if (c == 'A'+i) v[i].push_back(p);
        }
    }

    for (ll i=0; i<4; i++) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
    }

    vector<pair<char, ll>> ans;
    for (ll cnt=0; cnt<k; cnt++) {
        ll ans_idx = -1;
        ll ans_cal = -1;
        for (ll i=0; i<4; i++) {
            if (idx[i] >= v[i].size()) continue;
            val[i] += v[i][idx[i]];
            ll cal = val[0] * val[1] * val[2] * val[3];
            val[i] -= v[i][idx[i]];
            if (cal > ans_cal) {
                ans_idx = i;
                ans_cal = cal;
            }
        }
        if (ans_idx == -1) {
            return 0;
        }
        val[ans_idx] += v[ans_idx][idx[ans_idx]];
        ans.push_back({'A'+ans_idx, v[ans_idx][idx[ans_idx]]});
        idx[ans_idx]++;
    }

    for (auto aut : ans) {
        cout << aut.first << ' ' << aut.second << '\n';
    }
}
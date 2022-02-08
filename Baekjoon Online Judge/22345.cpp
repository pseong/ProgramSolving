#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int MAX_N=200000+10;
int N, Q;
ll prefix_sum_a[MAX_N], prefix_sum_ax[MAX_N];
vector<pll> home;

bool comp(const pll &a, const pll &b) {
    return a.F < b.F;
}

ll cal(ll q) {
    int idx = lower_bound(home.begin(), home.end(), pll(q, 0), comp) - home.begin();
    ll one = q*prefix_sum_a[idx-1];
    ll two = -prefix_sum_ax[idx-1];
    ll three = prefix_sum_ax[N-1]-prefix_sum_ax[idx-1];
    ll four = -q*(prefix_sum_a[N-1]-prefix_sum_a[idx-1]);
    return one + two + three + four;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    for(int i=0; i<N; i++) {
        ll a, x;
        cin >> a >> x;
        home.push_back({x, a});
    }

    sort(home.begin(), home.end());
    prefix_sum_a[0] = home[0].S;
    prefix_sum_ax[0] = home[0].F*home[0].S;
    for(int i=1; i<N; i++) {
        prefix_sum_a[i] = prefix_sum_a[i-1] + home[i].S;
        prefix_sum_ax[i] = prefix_sum_ax[i-1] + home[i].F*home[i].S;
    }

    for(int i=0; i<Q; i++) {
        ll q;
        cin >> q;
        cout << cal(q) << '\n';
    }
}
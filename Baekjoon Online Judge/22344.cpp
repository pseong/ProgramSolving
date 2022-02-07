#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const ll MAX_M=200000+10;
const ll MAX_N=100000+10;
ll N, M;
vector<pii> edge[MAX_M];
ll chk[MAX_N], n_coe[MAX_N], n_con[MAX_N];
bool fail, is_one;
ll defined_x=0;

void dfs(ll x, ll pre, ll coe, ll con) {
    chk[x] = 1;
    n_coe[x] = coe;
    n_con[x] = con;
    for (auto to : edge[x]) {
        ll y = to.F;
        ll w = to.S;
        if (y==pre) continue;
        if (chk[y]==1) {
            if (coe!=n_coe[y]) {
                if (w!=con+n_con[y]) fail = true;
            }
            else {
                if ((w-con-n_con[y])%2!=0) fail = true;
                else {
                    ll cal_x = coe*(w-con-n_con[y])/2;
                    if (is_one) {
                        if (cal_x!=defined_x) fail = true;
                    }
                    else {
                        is_one = true;
                        defined_x = cal_x;
                    }
                }
            }
        }
        else {
            dfs(y, x, -coe, w-con);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    dfs(1, 0, 1, 0);
    if (fail) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    vector<ll> ans;
    for (ll i=1; i<=N; i++) {
        ans.push_back(n_con[i]*n_coe[i]*(-1));
    }
    sort(ans.begin(), ans.end());
    ll x=ans[ans.size()/2];
    if (is_one) x = defined_x;
    for(ll i=1; i<=N; i++) {
        cout << x*n_coe[i]+n_con[i] << ' ';
    }
    return 0;
}
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

    int n, x, y;
    int an[202020]{ 0 };
    int chk[202020]{ 0 };
    cin >> n >> x >> y;
    vector<int> mark;
    mark.push_back(-1);
    for (int i=0; i<n; i++) {
        cin >> an[i];
        if (an[i] > x || an[i] < y) {
            chk[i] = -1;
            mark.push_back(i);
        }
        else if (an[i] == x) chk[i] = 2;
        else if (an[i] == y) chk[i] = 1;
    }
    mark.push_back(n);

    ll ans = 0;
    for (int i=1; i<mark.size(); i++) {
        int l = mark[i-1]+1;
        int r = mark[i]-1;
        if (r<l) continue;
        if (x != y) {
            vector<pii> v;
            for (int i=l; i<=r; i++) {
                if (an[i] == x) v.push_back({i, 2});
                else if (an[i] == y) v.push_back({i, 1});
            }
            for (int i=1; i<v.size(); i++) {
                if (v[i].second != v[i-1].second) {
                    ll a = v[i-1].first;
                    ll b = v[i].first;
                    ans += (a-l+1) * (r-b+1);
                    l = a+1;
                }
            }
        }
        else {
            ll cnt = r-l+1;
            ans += cnt;
            ans += cnt*(cnt-1)/2;
        }
    }
    cout << ans;
}
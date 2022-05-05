#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<pii> in, h, v;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        in.push_back({a, b});
    }
    in.push_back(in[0]);
    for (int i=0; i<n; i++) {
        int a1, b1, a2, b2;
        tie(a1, b1) = in[i];
        tie(a2, b2) = in[i+1];
        if (a1 == a2) {
            if (b1 > b2) swap(b1, b2);
            h.push_back({b1, 1});
            h.push_back({b2, -1});
        }
        else {
            if (a1 > a2) swap(a1, a2);
            v.push_back({a1, 1});
            v.push_back({a2, -1});
        }
    }
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int ans = 0;
    int now = 0;
    for (int i=0; i<(int)v.size(); i++) {
        if (v[i].second == -1) now--;
        else now++;
        ans = max(ans, now); 
    }
    for (int i=0; i<(int)h.size(); i++) {
        if (h[i].second == -1) now--;
        else now++;
        ans = max(ans, now);
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    vector<pi> v(6);
    for (int i=0; i<6; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    v.insert(v.end(), v.begin(), v.end());
    for (int i=3; i<12; i++) {
        if (v[i-3].first == v[i-1].first && v[i-2].first == v[i].first) {
            int a = v[i-3].second + v[i-1].second;
            int b = v[i-2].second + v[i].second;
            int h = v[i-1].second;
            int w = v[i-2].second;
            cout << (a*b - h*w) * k;
            return 0;
        }
    }
}
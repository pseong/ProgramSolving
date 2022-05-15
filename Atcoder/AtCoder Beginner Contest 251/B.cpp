#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w; cin >> n >> w;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    set<int> st;
    bitset<1000001> bs;
    for (int i=0; i<n; i++) {
        if (v[i] <= w) bs[v[i]] = 1;
        for (int j=i+1; j<n; j++) {
            if (v[i] + v[j] <= w) bs[v[i] + v[j]] = 1;
            for (int k=j+1; k<n; k++) {
                if (v[i] + v[j] + v[k] <= w) bs[v[i] + v[j] + v[k]] = 1;
            }
        }
    }
    cout << bs.count();
}
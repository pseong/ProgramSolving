#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> v;
    for (int i=1; i<=n; i++) {
        if (i == x) continue;
        v.push_back(i);
    }

    int r = v.size()/2;
    int l = r-1;
    if (v.size()%2 == 1 && x == n/2+1) {
        v.insert(v.begin()+x-1, x);
        l = x-2;
        r = x-1;
    }
    else cout << x << ' ';
    while (l >= 0 || r < v.size()) {
        if (r < v.size()) {
            cout << v[r] << ' ';
            r++;
        }
        if (l >= 0) {
            cout << v[l] << ' ';
            l--;
        }
    }
}
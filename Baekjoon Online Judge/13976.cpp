#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll mod =  1000000007;

typedef vector<vector<ll>> matrix;
matrix operator*(matrix &m1, matrix &m2) {
    int n = m1.size();
    int m = m2[0].size();
    int x = m1[0].size();
    assert(x == m2.size());
    matrix ret(n, vector<ll>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<x; k++) {
                ret[i][j] += m1[i][k] * m2[k][j] % mod;
                ret[i][j] += mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

matrix mpow(matrix m, ll x) {
    if (x == 0) return {{1, 1}, {1, 1}};
    if (x == 1) return m;
    matrix ret = mpow(m, x/2);
    ret = ret*ret;
    if (x%2 == 0) return ret;
    matrix one = {{4, -1}, {1, 0}};
    return ret*one;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    ll n; cin >> n;
    if (n == 0) cout << 1 << '\n';
    else if (n == 2) cout << 3 << '\n';
    else if (n%2) cout << 0 << '\n';
    else {
        matrix z = mpow({{4, -1}, {1, 0}}, (n-2)/2);
        cout << (z[0][0]*3 + z[0][1] + mod) % mod << '\n';
    }
}
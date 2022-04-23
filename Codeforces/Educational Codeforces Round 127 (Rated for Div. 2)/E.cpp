#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
string s;
ll n, cnt;
const ll mod = 998244353;

string dfs(int x) {
    if (x*2 >= s.size()) {
        return string(1, s[x]);
    }
    string left = dfs(x*2);
    string right = dfs(x*2+1);
    if (left > right) swap(left, right);
    if (left != right) cnt++;
    return string(1, s[x]) + left + right;
}

ll llpow(ll x, ll p) {
    if (p==0) return 1;
    if (p==1) return x;
    if (p%2==0) {
        ll a = llpow(x, p/2);
        return a*a % mod;
    }
    return x*llpow(x, p-1) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    s.insert(s.begin(), 'X');
    dfs(1);
    cout << llpow(2, cnt);
}
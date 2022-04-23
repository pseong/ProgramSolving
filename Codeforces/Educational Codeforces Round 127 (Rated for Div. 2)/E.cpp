#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
string s;
ll n, cnt;
using mint = modint998244353;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s;
    s.insert(s.begin(), 'X');
    dfs(1);
    mint ans;
    ans = 2;
    cout << ans.pow(cnt).val();
}
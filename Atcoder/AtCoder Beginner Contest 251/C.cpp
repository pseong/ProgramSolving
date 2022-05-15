#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_set<string> st;
    int best = 0;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        string s; int t;
        cin >> s >> t;
        if (st.find(s) == st.end()) {
            st.insert(s);
            if (best < t) {
                best = t;
                ans = i;
            }
        }
    }
    cout << ans;
}
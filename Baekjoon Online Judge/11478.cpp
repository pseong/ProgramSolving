#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<string> st;
    string s; cin >> s;
    int n = s.size();
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int len = j-i+1;
            st.insert(s.substr(i, len));
        }
    }
    cout << st.size();
}
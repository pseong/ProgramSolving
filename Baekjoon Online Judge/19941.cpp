#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> k >> s;
    int z = s.size();
    queue<int> ham;
    queue<int> peo;
    for (int i=0; i<z; i++) {
        if (s[i] == 'H') ham.push(i);
        else peo.push(i);
    }
    
    int ans = 0;
    while (ham.size() && peo.size()) {
        int p = peo.front(); peo.pop();
        if (ham.front() - p > k) continue;
        while (ham.size() && abs(ham.front() - p) > k) {
            ham.pop();
        }
        if (ham.size()) {
            ans++;
            ham.pop();
        }
    }
    cout << ans;
}
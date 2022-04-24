#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int v[20][26];
int cnt[26];
int n, k, ans;

void go(int idx) {
    if (idx == n) {
        int res = 0;
        for (int i=0; i<26; i++) {
            if (cnt[i] == k) res++;
        }
        ans = max(ans, res);
        return;
    }
    for (int i=0; i<26; i++) {
        cnt[i] += v[idx][i];
    }
    go(idx+1);
    for (int i=0; i<26; i++) {
        cnt[i] -= v[idx][i];
    }
    go(idx+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int k=0; k<s.size(); k++) {
            v[i][s[k]-'a']++;
        }
    }

    go(0);
    cout << ans << '\n';
}
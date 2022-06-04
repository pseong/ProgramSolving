#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> cnt(26, 0);
        vector<int> cnt2(26, 0);
        vector<int> chk(26 , 0);
        for (int i=0; i<2*n; i++) {
            string s;
            cin >> s;
            if (s.size() == 1) chk[s.back()-'a'] = 1;
            for (int x=0; x<(int) s.size(); x++) {
                cnt[s[x]-'a']++;
            }
        }
        string s;
        cin >> s;
        for (int x=0; x<(int) s.size(); x++) {
            cnt2[s[x]-'a']++;
        }

        vector<int> ans(26, 0);
        for (int i=0; i<26; i++) {
            ans[i] = cnt[i] - cnt2[i];
        }

        char a = '/';
        for (int i=0; i<26; i++) {
            if (ans[i]%2 == 1) {
                a = i+'a';
                break;
            }
        }
        cout << a << '\n';
    }
}
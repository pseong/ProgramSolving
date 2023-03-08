#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

void solve(int CASE) {
    string s;
    cin >> s;
    vector<int> cnt(26);
    int n = s.size();
    string ans(n, ' ');
    for (int i=0; i<n; i++) {
        cnt[s[i]-'a']++;
    }
    int l = 0;
    int r = n-1;
    for (int i=0; i<26; i++) {
        for (int j=l; j<l+cnt[i]/2; j++) {
            ans[j] = i + 'a';
        }
        for (int j=r; j>r-cnt[i]/2; j--) {
            ans[j] = i + 'a';
        }
        l = l + cnt[i]/2;
        r = r - cnt[i]/2;
        if (cnt[i] % 2) {
            int c = 0;
            for (int j=i+1; j<26; j++) {
                if (cnt[j]) c++;
            }
            if (c == 0) {
                ans[l] = i + 'a';
            }
            else if (c == 1) {
                char tmp = i + 'a';
                for (i++; i<26; i++) {
                    for (int j=l; j<l+cnt[i]/2; j++) {
                        ans[j] = i + 'a';
                    }
                    for (int j=r; j>r-cnt[i]/2; j--) {
                        ans[j] = i + 'a';
                    }
                    l = l + cnt[i]/2;
                    r = r - cnt[i]/2;
                    if (cnt[i] % 2) ans[l] = i + 'a';
                    ans[r] = tmp;
                }
            }
            else {
                ans[r] = i + 'a';
                for (i++; i<26; i++) {
                    for (int j=l; j<l+cnt[i]; j++) {
                        ans[j] = i + 'a';
                    }
                    l = l + cnt[i];
                }
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
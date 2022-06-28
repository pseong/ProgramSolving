#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n; cin >> n;
    vector<int> v(n), all, plus, minus;
    set<int> st;
    int zero = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        st.insert(v[i]);
        if (v[i] > 0) plus.push_back(v[i]);
        else if (v[i] < 0) minus.push_back(v[i]);
        else if (v[i] == 0) zero++;
        if (v[i] != 0) all.push_back(v[i]);
    }
    if (plus.size() >= 3 || minus.size() >= 3) {
        no();
        return;
    }
    for (int i=0; i<min(2LL, zero); i++) all.push_back(0);
    for (int i=0; i<(int) all.size(); i++) {
        for (int j=i+1; j<(int) all.size(); j++) {
            for (int k=j+1; k<(int) all.size(); k++) {
                int sum = all[i] + all[j] + all[k];
                if (st.find(sum) == st.end()) {
                    no();
                    return;
                }
            }
        }
    }
    yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}
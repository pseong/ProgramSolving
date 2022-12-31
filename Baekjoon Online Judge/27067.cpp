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

int n;

vector<int> cal(vector<int>& v, int idx, int x) {
    vector<int> ans(n + 1);
    for (int i=n; i>idx; i--) {
        ans[i] = v[i];
    }
    int k = 0;
    for (int i=idx-1; i>=1; i--) {
        if (v[i] == x) k = i;
    }
    assert(k != 0);
    ans[idx] = x;
    for (int i=idx-1; i>=k; i--) {
        ans[i] = v[i + 1];
    }
    for (int i=k-1; i>=1; i--) {
        ans[i] = v[i];
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) cin >> c[i];
    for (int i=n; i>=1; i--) {
        set<int> st;
        st.insert(a[i]);
        st.insert(b[i]);
        st.insert(c[i]);
        if (st.size() == 2) {
            vector<int> ans;
            if (a[i] == b[i]) ans = cal(c, i, a[i]);
            if (a[i] == c[i]) ans = cal(b, i, a[i]);
            if (b[i] == c[i]) ans = cal(a, i, b[i]);
            for (int i=1; i<=n; i++) {
                cout << ans[i] << ' ';
            }
            return 0;
        }
    }
}
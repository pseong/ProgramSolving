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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> val(300);
    val['*'] = 1;
    val['/'] = 1;
    int n;
    cin >> n;
    vector<int> v(n), w;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i=0; i<a; i++) w.push_back('+');
    for (int i=0; i<b; i++) w.push_back('-');
    for (int i=0; i<c; i++) w.push_back('*');
    for (int i=0; i<d; i++) w.push_back('/');
    sort(w.begin(), w.end());
    const int inf = 1e9;
    vector<int> ans{inf, -inf};
    do {
        vector<int> m;
        m.push_back(v[0] + 100);
        for (int i=0; i<(int)w.size(); i++) {
            m.push_back(w[i]);
            m.push_back(v[i+1] + 100);
        }
        stack<int> st;
        vector<int> e;
        for (int i=0; i<(int)m.size(); i++) {
            if (m[i] > 100) e.push_back(m[i]);
            else {
                while (st.size() && val[st.top()] >= val[m[i]]) {
                    e.push_back(st.top());
                    st.pop();
                }
                st.push(m[i]);
            }
        }
        while (st.size()) {
            e.push_back(st.top());
            st.pop();
        }
        for (int i=0; i<(int)e.size(); i++) {
            if (e[i] > 100) st.push(e[i] - 100);
            else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (e[i] == '+') st.push(a + b);
                else if (e[i] == '-') st.push(a - b);
                else if (e[i] == '*') st.push(a * b);
                else if (e[i] == '/') st.push(a / b);
            }
        }
        ans[0] = min(ans[0], st.top());
        ans[1] = max(ans[1], st.top());
        if (ans[0] == -19) {
            int ab = 3;
        }
    } while (next_permutation(w.begin(), w.end()));
    cout << ans[1] << '\n' << ans[0] << '\n';
}
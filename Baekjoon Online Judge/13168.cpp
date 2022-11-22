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
    
    int n, r;
    cin >> n >> r;
    map<string, int> mp;
    set<string> st;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }
    n = st.size();
    int idx = 1;
    for (auto& s : st) {
        mp[s] = idx;
        idx++;
    }
    int m;
    cin >> m;
    vector<int> lst;
    for (int i=0; i<m; i++) {
        string a;
        cin >> a;
        lst.push_back(mp[a]);
    }
    int k;
    cin >> k;
    const double inf = 10000000;
    vector<vector<double>> v(n + 1, vector<double>(n + 1, inf));
    for (int i=1; i<=n; i++) {
        v[i][i] = 0;
    }
    vector<tuple<string, string, string, double>> edges(k);
    for (int i=0; i<k; i++) {
        string a, b, c;
        double d;
        cin >> a >> b >> c >> d;
        edges[i] ={a, b, c, d};
        v[mp[b]][mp[c]] = min(v[mp[b]][mp[c]], d);
        v[mp[c]][mp[b]] = min(v[mp[c]][mp[b]], d);
    }

    auto tmp = v;
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    double one = 0;
    for (int i=1; i<(int)lst.size(); i++) {
        one += v[lst[i-1]][lst[i]];
    }
    for (int i=1; i<=n; i++) {
        v[i][i] = 0;
    }
    v.assign(n + 1, vector<double>(n + 1, inf));
    for (auto& [a, b, c, d] : edges) {
        if (a == "Mugunghwa" || a == "ITX-Saemaeul" || a == "ITX-Cheongchun") {
            d = 0;
        }
        if (a == "S-Train" || a == "V-Train") {
            d /= 2;
        }
        v[mp[b]][mp[c]] = min(v[mp[b]][mp[c]], d);
        v[mp[c]][mp[b]] = min(v[mp[c]][mp[b]], d);
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    double two = r;    
    for (int i=1; i<(int)lst.size(); i++) {
        two += v[lst[i-1]][lst[i]];
    }
    if (one > two) yes();
    else no();
}
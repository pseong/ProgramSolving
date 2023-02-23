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

int o[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    o['+'] = 1;
    o['-'] = 1;
    o['*'] = 2;
    o['/'] = 2;

    string s;
    cin >> s;
    stack<char> st;
    int n = s.size();
    for (int i=0; i<n; i++) {   
        if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
        else if (s[i] == ')') {
            while (st.size() && st.top() != '(') cout << st.top(), st.pop();
            st.pop();
        }
        else if (s[i] == '(') st.push(s[i]);
        else {
            while (st.size() && o[st.top()] >= o[s[i]]) cout << st.top(), st.pop();
            st.push(s[i]);
        }
    }
    while (st.size()) cout << st.top(), st.pop();
}
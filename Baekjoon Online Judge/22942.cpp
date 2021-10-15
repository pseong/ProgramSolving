#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<pii> v;
    for(int i=0; i<n; i++) {
        int x, r;
        cin >> x >> r;
        v.push_back({x-r, x+r});
    }
    sort(v.begin(), v.end());

    stack<int> st;
    bool fail=false;
    for(int i=0; i<n; i++) {
        if(st.empty()) {
            st.push(v[i].S);
            continue;
        }
        int s, e;
        tie(s, e) = v[i];
        if(s>st.top()) {
            while(!st.empty() && s>st.top()) {
                st.pop();
            }
        }
        if(st.empty()) {
            st.push(v[i].S);
            continue;
        }
        if(e>=st.top()) {
            fail = true;
            break;
        }
        if(e<st.top()) {
            st.push(e);
        }
    }
    if(fail) cout << "NO";
    else cout << "YES";
}
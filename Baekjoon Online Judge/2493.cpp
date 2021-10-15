#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    stack<pii> st;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        while(!st.empty() && st.top().F<a) {
            st.pop();
        }
        if(st.empty()) {
            cout << 0 << ' ';
        }
        else {
            cout << st.top().S << ' ';
        }
        st.push({a, i});
    }
}

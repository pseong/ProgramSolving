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

    set<int> st;
    for(int i=0; i<4; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
    cout << 4-st.size();
}
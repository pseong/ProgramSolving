#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;
    stack<int> st;
    while(k--) {
        int a;
        cin >> a;
        if(a==0) st.pop();
        else st.push(a);
    }
    int ans=0;
    while(!st.empty()) {
        int a = st.top();
        st.pop();
        ans += a;
    }
    cout << ans;
}
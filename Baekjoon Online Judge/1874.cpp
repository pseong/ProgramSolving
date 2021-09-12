#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    stack<int> st;
    st.push(0);
    int n;
    cin >> n;
    vector<char> ans;
    int i = 1;
    for(int j = 0; j < n; j++) {
        int a;
        cin >> a;
        if(st.top() == a) {
            st.pop();
            ans.push_back('-');
        }
        else {
            while(st.top() != a) {
                if(i > n) {
                    cout << "NO";
                    return 0;
                }
                st.push(i);
                ans.push_back('+');
                i++;
            }
            st.pop();
            ans.push_back('-');
        }
    }
    for(char c : ans)
        cout << c << '\n';
}
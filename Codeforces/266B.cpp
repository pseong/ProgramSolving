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

    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    while(t--) {
        vector<int> sw;
        for(int i=0; i<s.size()-1; i++) {
            if(s[i]=='B' && s[i+1]=='G') sw.push_back(i);
        }
        for(int i : sw) {
            swap(s[i], s[i+1]);
        }
    }
    cout << s;
}
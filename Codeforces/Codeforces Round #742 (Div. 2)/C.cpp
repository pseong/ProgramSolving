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

    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int a=0;
        int b=0;
        for(int i=0; i<s.size(); i+=2) {
            a *= 10;
            a += s[i]-'0';
        }
        for(int i=1; i<s.size(); i+=2) {
            b *= 10;
            b += s[i]-'0';
        }
        cout << (a+1)*(b+1)-2 << '\n';
    }
}
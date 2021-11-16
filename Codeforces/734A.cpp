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
    string s;
    cin >> s;
    int a=0, b=0;
    for(char c : s) {
        if(c=='A') a++;
        else b++;
    }
    if(a>b) {
        cout << "Anton";
    }
    else if(b>a) {
        cout << "Danik";
    }
    else {
        cout << "Friendship";
    }
}
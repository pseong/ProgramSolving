#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int many[200]{ 0 };

    bool what = false;
    int ans = 0;

    char c[1000000]{ 0 };
    for(int i = 0; i < 1000000; i++) {
        c[i] = getchar();
    }
    for(int i = 0; i < 1000000; i++) {
        if(c[i] == 0) continue;
        many[c[i]]++;
        if(many[ans] == many[c[i]] && ans != c[i])
            what = true;
        if(many[ans] < many[c[i]]) {
            ans = c[i];
            what = false;
        }
    }
    if(what) cout << '?';
    else cout << (char)toupper(ans);
}
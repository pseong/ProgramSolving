#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n[3], m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n[0] >> n[1] >> n[2] >> m;
        sort(n, n+3);
        int mx=max(0, n[0]-1)+max(0, n[1]-1)+max(0, n[2]-1);
        int mn=max(0, n[2]-(n[0]+n[1]+1));
        if(m>=mn&&m<=mx) cout << "YES\n";
        else cout << "NO\n";
    }
}
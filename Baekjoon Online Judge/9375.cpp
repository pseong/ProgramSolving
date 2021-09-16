#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<string, int> m;
        while(n--) {
            string a, b;
            cin >> a >> b;
            m[b]++;
        }
        int ans=1;
        for(auto a : m) {
            ans *= (a.second+1);
        }
        cout << ans-1 << '\n';
    }
}
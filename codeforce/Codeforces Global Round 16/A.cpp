#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        int x=n-ceil((double)n/2)+1;
        int y=floor((double)s/x);
        cout << y << '\n';
    }
}
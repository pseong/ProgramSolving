#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;
        int a=ceil((double)n/h);
        int b=(n-1)%h+1;
        cout << b;
        cout.width(2);
        cout.fill('0');
        cout << a << '\n';
    }
}
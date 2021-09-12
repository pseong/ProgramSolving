#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    int ans4 = a*b;
    for(int i=10; b>0;) {
        int t = b-(b/10)*10;
        cout << t*a << '\n';
        b/=i;
    }
    cout << ans4;
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if(a==c) cout << e << ' ';
    else if(a==e) cout << c << ' ';
    else cout << a << ' ';
    if(b==d) cout << f;
    else if(b==f) cout << d;
    else cout << b;
}
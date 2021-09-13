#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        long long a, b, c;
        cin >> a >> b >> c;
        if(a==0&&b==0&&c==0) break;
        if(c<b) swap(c,b);
        if(c<a) swap(c,a);
        if(a*a+b*b==c*c) cout << "right\n";
        else cout << "wrong\n";
    }
}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int a=x1*y2+x2*y3+x3*y1;
    int b=x2*y1+x3*y2+x1*y3;
    if(a-b>0) cout << 1;
    else if(a-b<0) cout << -1;
    else cout << 0;
}
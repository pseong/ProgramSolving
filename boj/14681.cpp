#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> x;
    cin >> y;
    int ans=0;
    if(x>0) {
        if(y>0) {
            ans =1;
        } else {
            ans = 4;
        }
    } else {
        if(y>0) {
            ans = 2;
        } else {
            ans = 3;
        }
    }
    cout << ans;
}
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double gap=sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));
        int ans=-1;
        if(x1==x2&&y1==y2) {
            if(r1!=r2) ans = 0;
        }
        else if(gap==r1+r2) ans = 1;
        else if(gap>r1+r2) ans = 0;
        else if(gap<r1+r2) {
            if(gap+r2==r1||gap+r1==r2) ans = 1;
            else if(r2>gap+r1||r1>gap+r2) ans = 0;
            else ans = 2;
        }
        cout << ans << '\n';
    }
}
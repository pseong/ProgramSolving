#include <iostream>
#include <iomanip>
#include <queue>
#include <tuple>
#include <cmath>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ld x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    ld d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    
    cout << fixed << setprecision(3);
    if(d>r1+r2) {
        cout << 0.0;
    } else {
        if(d+r2<=r1) {
            cout << M_PI*r2*r2;
        } else if(d+r1<=r2) {
            cout << M_PI*r1*r1;
        } else {
            ld cos1=(r1*r1-r2*r2+d*d)/(2*r1*d);
            ld cos2=(r2*r2-r1*r1+d*d)/(2*r2*d);
            ld theta1=acos(cos1);
            ld theta2=acos(cos2);
            ld sin1=sin(theta1);
            ld sin2=sin(theta2);
            ld ans1=r1*r1*(theta1-sin1*cos1);
            ld ans2=r2*r2*(theta2-sin2*cos2);
            cout << ans1+ans2;
        }
    }
}
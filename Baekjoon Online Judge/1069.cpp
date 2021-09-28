#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cmath>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    ld x, y, d, t;
    cin >> x >> y >> d >> t;
    ld dist=sqrt(x*x+y*y);
    cout << fixed << setprecision(15);
    if(d<t) cout << dist;
    else {
        int cnt=dist/d;
        dist -= cnt*d;
        ld cal1=dist;
        ld cal2=-(dist-d)+t;
        ld cal3=t*2;
        if(cnt>=1) cal3 = t;
        cout << (ld)cnt*t + min({cal1, cal2, cal3});
    }
}
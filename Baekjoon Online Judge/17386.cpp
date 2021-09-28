#include <iostream>

using namespace std;

typedef long long ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll a=x1*y2+x2*y3+x3*y1;
    ll b=x2*y1+x3*y2+x1*y3;
    return a-b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    
    ll res1, res2, res3, res4;
    res1 = ccw(x1, y1, x2, y2, a1, b1);
    res2 = ccw(x1, y1, x2, y2, a2, b2);
    res3 = ccw(a1, b1, a2, b2, x1, y1);
    res4 = ccw(a1, b1, a2, b2, x2, y2);
    if(res1>0&&res2<0||res1>0&&res2<0) {
        if(res3>0&&res4<0||res3<0&&res4>0) {
            cout << 1;
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
}
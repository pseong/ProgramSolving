#include <iostream>

using namespace std;

typedef long long ll;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll a=x1*y2+x2*y3+x3*y1;
    ll b=x2*y1+x3*y2+x1*y3;
    if(a-b>0) return 1;
    else if(a-b<0) return -1;
    else return 0;
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
    if(x1==x2&&y1==y2 || a1==a2&&b1==b2) {
        cout << 0;
        return 0;
    }
    if(res1*res2<=0) {
        if(res3*res4<=0) {
            if(!res1&&!res2&&!res3&&!res4) {
                if(x1>x2) swap(x1, x2);
                if(a1>a2) swap(a1, a2);
                if(x2<a1 || x1>a2) {
                    cout << 0;
                } else {
                    if(y1>y2) swap(y1, y2);
                    if(b1>b2) swap(b1, b2);
                    if(y2<b1 || y1>b2) {
                        cout << 0;
                    } else {
                        cout << 1;
                    }
                }
            } else {
                cout << 1;
            }
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
}
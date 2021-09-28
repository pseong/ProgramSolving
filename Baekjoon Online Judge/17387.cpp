#include <iostream>
#define fi first
#define se second

typedef long long ll;
using namespace std;

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

    ll a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    pair<ll, ll> p1={a, b};
    pair<ll, ll> p2={c, d};
    pair<ll, ll> p3={e, f};
    pair<ll, ll> p4={g, h};
    
    ll res1, res2, res3, res4;
    res1 = ccw(p1.fi, p1.se, p2.fi, p2.se, p3.fi, p3.se);
    res2 = ccw(p1.fi, p1.se, p2.fi, p2.se, p4.fi, p4.se);
    res3 = ccw(p3.fi, p3.se, p4.fi, p4.se, p1.fi, p1.se);
    res4 = ccw(p3.fi, p3.se, p4.fi, p4.se, p2.fi, p2.se);
    if(res1*res2<=0) {
        if(res3*res4<=0) {
            if(!res1&&!res2&&!res3&&!res4) {
                if(p1.fi>p2.fi) swap(p1, p2);
                if(p3.fi>p4.fi) swap(p3, p4);
                if(p2.fi<p3.fi || p1.fi>p4.fi) {
                    cout << 0;
                } else {
                    if(p1.se>p2.se) swap(p1, p2);
                    if(p3.se>p4.se) swap(p3, p4);
                    if(p2.se<p3.se || p1.se>p4.se) {
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
#include <iostream>
#include <iomanip>
#define fi first
#define se second

typedef long double ld;
using namespace std;

pair<ld, ld> p1, p2, p3, p4;

ld ccw(ld x1, ld y1, ld x2, ld y2, ld x3, ld y3) {
    ld a=x1*y2+x2*y3+x3*y1;
    ld b=x2*y1+x3*y2+x1*y3;
    if(a-b>0) return 1;
    else if(a-b<0) return -1;
    else return 0;
}

void calCross() {
    ld a, b, c, d, x, y;
    if(p2.fi==p1.fi) {
        x = p2.fi;
        c = (p4.se-p3.se)/(p4.fi-p3.fi);
        d = p3.se-(p4.se-p3.se)*p3.fi/(p4.fi-p3.fi);
        y = c*x+d;
        cout << fixed << setprecision(11) << x << ' ' << y;
        return;
    }

    a = (p2.se-p1.se)/(p2.fi-p1.fi);
    b = p1.se-(p2.se-p1.se)*p1.fi/(p2.fi-p1.fi);

    if(p3.fi==p4.fi) {
        x = p3.fi;
        y = a*x+b;
        cout << fixed << setprecision(11) << x << ' ' << y;
        return;
    }
    c = (p4.se-p3.se)/(p4.fi-p3.fi);
    d = p3.se-(p4.se-p3.se)*p3.fi/(p4.fi-p3.fi);

    x = (d-b)/(a-c);
    y = (d-b)/(a-c)*a+b;
    cout << fixed << setprecision(11) << x << ' ' << y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ld a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    p1={a, b};
    p2={c, d};
    p3={e, f};
    p4={g, h};
    
    ld res1, res2, res3, res4;
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
                        cout << 1 << '\n';
                        if(p2.se==p3.se && p2.fi==p3.fi) {
                            cout << p2.fi << ' ' << p2.se;
                        } else if(p1.se==p4.se && p1.fi==p4.fi) {
                            cout << p1.fi << ' ' << p1.se;
                        }
                    }
                }
            } else {
                cout << 1 << '\n';
                calCross();
            }
        } else {
            cout << 0;
        }
    } else {
        cout << 0;
    }
}
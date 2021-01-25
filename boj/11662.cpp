#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    double lo = 0;
    double hi = 0;

    for(int i = 0; i < 1000; i++) {
        double mx1 = (2*ax + bx) / 3;
        double my1 = (2*ay + by) / 3;

        double mx2 = (ax + 2*bx) / 3;
        double my2 = (ay + 2*by) / 3;

        double gx1 = (2*cx + dx) / 3;
        double gy1 = (2*cy + dy) / 3;

        double gx2 = (cx + 2*dx) / 3;
        double gy2 = (cy + 2*dy) / 3;

        lo = pow(mx1 - gx1, 2) + pow(my1 - gy1, 2);
        hi = pow(mx2 - gx2, 2) + pow(my2 - gy2, 2);

        if(lo <= hi) {
            bx = mx2;
            by = my2;
            dx = gx2;
            dy = gy2;
        }
        else {
            ax = mx1;
            ay = my1;
            cx = gx1;
            cy = gy1;
        }
    }

    setprecision(7);
    std::cout << fixed << sqrt((hi + lo) / 2);
}
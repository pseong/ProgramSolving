#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Point {
    ll x, y;
};

Point operator+(const Point& p1, const Point& p2) {
    return Point{ p1.x + p2.x, p1.y + p2.y };
}

Point operator-(const Point& p1, const Point& p2) {
    return Point{ p1.x - p2.x, p1.y - p2.y };
}

ll cross(Point p1, Point p2) {
    return p1.x * p2.y - p2.x * p1.y;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<Point> pts(n);
    for (int i=0; i<n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    ll s = 0;
    for (int i=1; i<n; i++) {
        s += abs(cross(pts[i]-pts[0], pts[i-1]-pts[0]));
    }
    
    ll ans = 512e16;
    ll e = 0;
    int q = 1;
    for (int p=0; p<n; p++) {
        while (e*4 < s) {
            e += abs(cross(pts[q]-pts[p], pts[(q+1)%n]-pts[p]));
            q++; q%=n;
            ans = min(ans, abs(4*e-s));
        }
        e -= abs(cross(pts[p]-pts[q], pts[(p+1)%n]-pts[q]));
        ans = min(ans, abs(4*e-s));
    }
    cout << ans << '\n';
    return 0;
}
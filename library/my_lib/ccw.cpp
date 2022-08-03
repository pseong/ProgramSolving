#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Point {
    ll x, y;
};

struct Line {
    Point p1, p2;
};

struct Geo {
    static ll ccw(Point p1, Point p2, Point p3) {
        ll a = p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
        ll b = p1.y*p2.x + p2.y*p3.x + p3.y*p1.x;
        if (a-b > 0) return 1;
        else if (a-b < 0) return -1;
        else return 0;
    }

    static bool cross(Line l1, Line l2) {
        ll res1 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
        ll res2 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
        if (res1 == 0 && res2 == 0) {
            if (l1.p1.x == l1.p2.x) {
                if (l1.p1.y > l1.p2.y) swap(l1.p1, l1.p2);
                if (l2.p1.y > l2.p2.y) swap(l2.p1, l2.p2);
                if (l1.p1.y <= l2.p2.y && l1.p2.y >= l2.p1.y) return 1;
                else return 0;
            }
            else {
                if (l1.p1.x > l1.p2.x) swap(l1.p1, l1.p2);
                if (l2.p1.x > l2.p2.x) swap(l2.p1, l2.p2);
                if (l1.p1.x <= l2.p2.x && l1.p2.x >= l2.p1.x) return 1;
                else return 0;
            }
        }
        else if (res1 <= 0 && res2 <= 0) return 1;
        else return 0;
    }

    static tuple<bool, double, double> intersect(Line l1, Line l2) {
        if (cross(l1, l2) == 0) return {0, INFINITY, INFINITY};
        if (l1.p2.x - l1.p1.x == 0 && l2.p2.x - l2.p1.x == 0) {
            if (l1.p1.y > l1.p2.y) swap(l1.p1, l1.p2);
            if (l2.p1.y > l2.p2.y) swap(l2.p1, l2.p2);
            if (l1.p2.y == l2.p1.y) return {1, l1.p2.x, l1.p2.y};
            if (l1.p1.y == l2.p2.y) return {1, l1.p1.x, l1.p1.y};
            return {1, INFINITY, INFINITY};
        }
        else if (l1.p2.x - l1.p1.x == 0) {
            double c = (double)(l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);
            double d = l2.p1.y - c*l2.p1.x;
            return {1, l1.p1.x, c*l1.p1.x + d};
        }
        else if (l2.p2.x - l2.p1.x == 0) {
            double a = (double)(l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
            double b = l1.p1.y - a*l1.p1.x;
            return {1, l2.p1.x , a*l2.p1.x + b};
        }
        if (l1.p1.x > l1.p2.x) swap(l1.p1, l1.p2);
        if (l2.p1.x > l2.p2.x) swap(l2.p1, l2.p2);
        if (l1.p1.x == l2.p2.x) return {1, l1.p1.x, l1.p1.y};
        else if (l1.p2.x == l2.p1.x) return {1, l1.p2.x, l1.p2.y};
        double a = (double)(l1.p2.y - l1.p1.y) / (l1.p2.x - l1.p1.x);
        double b = l1.p1.y - a*l1.p1.x;
        double c = (double)(l2.p2.y - l2.p1.y) / (l2.p2.x - l2.p1.x);
        double d = l2.p1.y - c*l2.p1.x;
        if (a == c) return {1, INFINITY, INFINITY};
        double x = (double)(d - b) / (a - c);
        double y = a*x + b;
        return {1, x, y};
    }
};
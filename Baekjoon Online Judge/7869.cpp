#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double PI = acos(-1);
    
    cout << fixed << setprecision(3);
    if (d > r1+r2) {
        cout << 0.0;
    }
    else {
        if (d+r2 <= r1) {
            cout << PI*r2*r2;
        }
        else if (d+r1 <= r2) {
            cout << PI*r1*r1;
        }
        else {
            double cos1 = (r1*r1-r2*r2+d*d)/(2*r1*d);
            double cos2 = (r2*r2-r1*r1+d*d)/(2*r2*d);
            double theta1 = 2*acos(cos1);
            double theta2 = 2*acos(cos2);
            double ans1=r1*r1*(theta1-sin(theta1))/2;
            double ans2=r2*r2*(theta2-sin(theta2))/2;
            cout << ans1+ans2;
        }
    }
}
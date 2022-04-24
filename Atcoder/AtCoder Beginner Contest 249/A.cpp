#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    swap(a, b);
    swap(e, d);
    int loopT = x/(b+c);
    int T = loopT * b * a;
    int left = x - loopT*(b+c);
    T += min(left, b) * a;

    int loopA = x/(e+f);
    int A = loopA * e * d;
    left = x - loopA*(e+f);
    A += min(left, e) * d;

    if (T == A) cout << "Draw";
    else if (T > A) cout << "Takahashi";
    else cout << "Aoki";
}
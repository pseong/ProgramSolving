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

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx>& v, bool inv) {
    int s = v.size();

    for (int i=1, j=0; i<s; i++) {
        int bit = s/2;
        while (j >= bit) {
            j -= bit;
            bit /= 2;
        }
        j += bit;
        if (i < j) swap(v[i], v[j]);
    }

    for (int k=1; k<s; k*=2) {
        double angle = (inv ? PI/k : -PI/k);
        cpx dir(cos(angle), sin(angle));

        for (int i=0; i<s; i+=k*2) {
            cpx unit(1, 0);
            for (int j=0; j<k; j++) {
                cpx a = v[i+j];
                cpx b = v[i+j+k] * unit;

                v[i+j] = a + b;
                v[i+j+k] = a - b;

                unit *= dir;
            }
        }
    }

    if (inv) {
        for (int i=0; i<s; i++) {
            v[i] /= s;
        }
    }
}

vector<cpx> mul(vector<cpx>& v, vector<cpx>& v2) {
    int s = 1;
    while (s < max(v.size(), v2.size())) s *= 2;

    v.resize(s);
    FFT(v, 0);
    v2.resize(s);
    FFT(v2, 0);

    vector<cpx> w(s);
    for (int i=0; i<s; i++) {
        w[i] = v[i] * v2[i];
    }
    FFT(w, 1);

    return w;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<cpx> v(n*2), v2(n);
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[i] = v[i+n] = cpx(x, 0);
    }
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        v2[n-1-i] = cpx(x, 0);
    }
    vector<cpx> w = mul(v, v2);

    int ans = 0;
    for (int i=0; i<(int)w.size(); i++) {
        ans = max(ans, (int)round(w[i].real()));
    }

    cout << ans << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}
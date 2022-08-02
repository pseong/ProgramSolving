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

vector<cpx> mul(vector<cpx>& a, vector<cpx>& b) {
    vector<cpx> pa = a, pb = b;
    int s = 1;
    while (s < pa.size()*2 || s < pb.size()*2) s *= 2;

    pa.resize(s);
    FFT(pa, 0);
    pb.resize(s);
    FFT(pb, 0);

    vector<cpx> w(s);
    for (int i=0; i<s; i++) {
        w[i] = pa[i] * pb[i];
    }
    FFT(w, 1);
    for (int i=0; i<(int)w.size(); i++) {
        w[i] = cpx(round(w[i].real()), round(w[i].imag()));
    }
    return w;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vector<cpx> v1(n), v2(m);
    for (int i=0; i<n; i++) if (a[i] == 'R') v1[i] = cpx(1, 0);
    for (int i=0; i<m; i++) if (b[i] == 'P') v2[m-1-i] = cpx(1, 0);
    vector<cpx> res1 = mul(v1, v2);
    v1.assign(n, cpx(0, 0)); v2.assign(m, cpx(0, 0));
    for (int i=0; i<n; i++) if (a[i] == 'S') v1[i] = cpx(1, 0);
    for (int i=0; i<m; i++) if (b[i] == 'R') v2[m-1-i] = cpx(1, 0);
    vector<cpx> res2 = mul(v1, v2);
    v1.assign(n, cpx(0, 0)); v2.assign(m, cpx(0, 0));
    for (int i=0; i<n; i++) if (a[i] == 'P') v1[i] = cpx(1, 0);
    for (int i=0; i<m; i++) if (b[i] == 'S') v2[m-1-i] = cpx(1, 0);
    vector<cpx> res3 = mul(v1, v2);

    int ans = 0;
    for (int i=m-1; i<(int)res1.size(); i++) {
        int sum = res1[i].real() + res2[i].real() + res3[i].real();
        ans = max(ans, sum);
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
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

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> p(1000001, 1);
    vector<cpx> v(500001);

    for (ll i=3; i<=1000000; i+=2) {
        if (p[i]) {
            v[(i-1)/2] = cpx(1, 0);
            for (ll j=i*i; j<=1000000; j+=i) {
                p[j] = 0;
            }
        }
    }
    vector<cpx> res = mul(v, v);

    cin >> T;
    for (int t=1; t<=T; t++) {
        int n;
        cin >> n;
        if (n == 4) {
            cout << 1 << '\n';
            continue;
        }
        int ans = 0;
        cout << int(res[n/2-1].real() / 2 + 0.5) << '\n';
    }
}
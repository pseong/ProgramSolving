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

vector<cpx> mul(vector<cpx> a, vector<cpx> b) {
    int s = 1;
    while (s < a.size() || s < b.size()) s *= 2;
    s *= 2;

    a.resize(s);
    FFT(a, 0);
    b.resize(s);
    FFT(b, 0);

    vector<cpx> w(s);
    for (int i=0; i<s; i++) {
        w[i] = a[i] * b[i];
    }
    FFT(w, 1);
    for (int i=0; i<(int)w.size(); i++) {
        w[i] = cpx(round(w[i].real()), round(w[i].imag()));
    }
    return w;
}

void solve(int CASE) {
    int n;
    cin >> n;
    vector<cpx> v(n);
    vector<int> cnt(n);
    for (ll i=1; i<=n-1; i++) {
        v[i*i % n] = cpx(round(v[i*i % n].real()+1), 0);
        cnt[i*i*2 % n]++;
    }
    vector<cpx> res = mul(v, v);
    ll ans = 0;
    for (ll i=1; i<n; i++) {
        int x = res[i*i%n].real() + res[n+i*i%n].real();
        ans += (x - cnt[i*i%n]) / 2 + cnt[i*i%n];
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
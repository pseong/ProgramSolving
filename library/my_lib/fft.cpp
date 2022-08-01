#include <bits/stdc++.h>
using namespace std;

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
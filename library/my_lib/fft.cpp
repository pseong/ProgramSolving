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

vector<ll> mul(vector<ll>& a, vector<ll>& b) {
    vector<cpx> pa(a.begin(), a.end()), pb(b.begin(), b.end());
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
    
    vector<ll> ret(s);
    for (int i=0; i<s; i++) {
        ret[i] = (ll)round(w[i].real());
    }
    return ret; // real() 로 출력할땐 (ll) 형변환 해야함.
}
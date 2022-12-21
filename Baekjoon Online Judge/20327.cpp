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

int v[500][500];

void sw(int k, int a, int b, int x, int y) {
    int n = (1 << k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            swap(v[a*n+i+1][b*n+j+1], v[x*n+i+1][y*n+j+1]);
        }
    }
}

void cp(int k, int a, int b, int x, int y) {
    int n = (1 << k);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            v[x*n+i+1][y*n+j+1] = v[a*n+i+1][b*n+j+1];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    n = 1<<n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    while (r--) {
        int k, l;
        cin >> k >> l;
        if (k == 1) {
            int s = (1 << l);
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=0; i<s/2; i++) {
                        for (int j=b; j<=y; j++) {
                            swap(v[a+i][j], v[x-i][j]);
                        }
                    }
                }
            }
        }
        else if (k == 2) {
            int s = (1 << l);
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=a; i<=x; i++) {
                        for (int j=0; j<s/2; j++) {
                            swap(v[i][b+j], v[i][y-j]);
                        }
                    }
                }
            }
        }
        else if (k == 3) {
            int s = (1 << l);
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=0; i<s/2; i++) {
                        for (int j=0; j<s/2; j++) {
                            int tmp = v[a+i][b+j];
                            v[a+i][b+j] = v[a+s-1-j][b+i];
                            v[a+s-1-j][b+i] = v[a+s-1-i][b+s-1-j];
                            v[a+s-1-i][b+s-1-j] = v[a+j][b+s-1-i];
                            v[a+j][b+s-1-i] = tmp;
                        }
                    }
                }
            }
        }   
        else if (k == 4) {
            int s = (1 << l);
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=0; i<s/2; i++) {
                        for (int j=0; j<s/2; j++) {
                            int tmp = v[a+i][b+j];
                            v[a+i][b+j] = v[a+s-1-j][b+i];
                            v[a+s-1-j][b+i] = v[a+s-1-i][b+s-1-j];
                            v[a+s-1-i][b+s-1-j] = v[a+j][b+s-1-i];
                            v[a+j][b+s-1-i] = tmp;
                        }
                    }
                }
            }
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=0; i<s/2; i++) {
                        for (int j=0; j<s/2; j++) {
                            int tmp = v[a+i][b+j];
                            v[a+i][b+j] = v[a+s-1-j][b+i];
                            v[a+s-1-j][b+i] = v[a+s-1-i][b+s-1-j];
                            v[a+s-1-i][b+s-1-j] = v[a+j][b+s-1-i];
                            v[a+j][b+s-1-i] = tmp;
                        }
                    }
                }
            }
            for (int a=1; a<=n; a+=s) {
                for (int b=1; b<=n; b+=s) {
                    int x = a + s - 1;
                    int y = b + s - 1;
                    for (int i=0; i<s/2; i++) {
                        for (int j=0; j<s/2; j++) {
                            int tmp = v[a+i][b+j];
                            v[a+i][b+j] = v[a+s-1-j][b+i];
                            v[a+s-1-j][b+i] = v[a+s-1-i][b+s-1-j];
                            v[a+s-1-i][b+s-1-j] = v[a+j][b+s-1-i];
                            v[a+j][b+s-1-i] = tmp;
                        }
                    }
                }
            }
        }
        else if (k == 5) {
            int s = (1 << l);
            for (int i=0; i<n/s/2; i++) {
                for (int j=0; j<n/s; j++) {
                    sw(l, i, j, n/s-1-i, j);
                }
            }
        }
        else if (k == 6) {
            int s = (1 << l);
            for (int i=0; i<n/s; i++) {
                for (int j=0; j<n/s/2; j++) {
                    sw(l, i, j, i, n/s-1-j);
                }
            }
        }
        else if (k == 7) {
            int s = (1 << l);
            for (int i=0; i<n/s/2; i++) {
                for (int j=0; j<n/s/2; j++) {
                    cp(l, i, j, n/s, n/s);
                    cp(l, n/s-1-j, i, i, j);
                    cp(l, n/s-1-i, n/s-1-j, n/s-1-j, i);
                    cp(l, j, n/s-1-i, n/s-1-i, n/s-1-j);
                    cp(l, n/s, n/s, j, n/s-1-i);
                }
            }
        }
        else if (k == 8) {
            int s = (1 << l);
            for (int i=0; i<n/s/2; i++) {
                for (int j=0; j<n/s/2; j++) {
                    cp(l, i, j, n/s, n/s);
                    cp(l, n/s-1-j, i, i, j);
                    cp(l, n/s-1-i, n/s-1-j, n/s-1-j, i);
                    cp(l, j, n/s-1-i, n/s-1-i, n/s-1-j);
                    cp(l, n/s, n/s, j, n/s-1-i);
                }
            }
            for (int i=0; i<n/s/2; i++) {
                for (int j=0; j<n/s/2; j++) {
                    cp(l, i, j, n/s, n/s);
                    cp(l, n/s-1-j, i, i, j);
                    cp(l, n/s-1-i, n/s-1-j, n/s-1-j, i);
                    cp(l, j, n/s-1-i, n/s-1-i, n/s-1-j);
                    cp(l, n/s, n/s, j, n/s-1-i);
                }
            }
            for (int i=0; i<n/s/2; i++) {
                for (int j=0; j<n/s/2; j++) {
                    cp(l, i, j, n/s, n/s);
                    cp(l, n/s-1-j, i, i, j);
                    cp(l, n/s-1-i, n/s-1-j, n/s-1-j, i);
                    cp(l, j, n/s-1-i, n/s-1-i, n/s-1-j);
                    cp(l, n/s, n/s, j, n/s-1-i);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}
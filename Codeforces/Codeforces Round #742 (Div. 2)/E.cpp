#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=200005;
int an[N], k;
ll seg[N*4][4], ans;

ll f(int x) {
    return ((ll)x*(x+1))/2;
}

void calc(int i, int l, int r) {
    int m=(l+r)/2;
    if(seg[i*2][3]&&seg[i*2+1][3]) {
        if(an[m]>an[m+1]) {
            seg[i][0] = 0;
            seg[i][1] = m-l+1;
            seg[i][2] = r-m;
            seg[i][3] = 0;
        }
        else {
            seg[i][0] = 0;
            seg[i][1] = 0;
            seg[i][2] = 0;
            seg[i][3] = 1;
        }
    }
    else if(seg[i*2][3]) {
        if(an[m]>an[m+1]) {
            seg[i][0] = seg[i*2+1][0]+f(seg[i*2+1][1]);
            seg[i][1] = m-l+1;
            seg[i][2] = seg[i*2+1][2];
            seg[i][3] = 0;
        }
        else {
            seg[i][0] = seg[i*2+1][0];
            seg[i][1] = m-l+1+seg[i*2+1][1];
            seg[i][2] = seg[i*2+1][2];
            seg[i][3] = 0;
        }
    }
    else if(seg[i*2+1][3]) {
        if(an[m]>an[m+1]) {
            seg[i][0] = seg[i*2][0]+f(seg[i*2][2]);
            seg[i][1] = seg[i*2][1];
            seg[i][2] = r-m;
            seg[i][3] = 0;
        }
        else {
            seg[i][0] = seg[i*2][0];
            seg[i][1] = seg[i*2][1];
            seg[i][2] = r-m+seg[i*2][2];
            seg[i][3] = 0;
        }
    }
    else {
        if(an[m]>an[m+1]) {
            seg[i][0] = seg[i*2][0]+seg[i*2+1][0]+f(seg[i*2][2])+f(seg[i*2+1][1]);
            seg[i][1] = seg[i*2][1];
            seg[i][2] = seg[i*2+1][2];
            seg[i][3] = 0;
        }
        else {
            seg[i][0] = seg[i*2][0]+seg[i*2+1][0]+f(seg[i*2][2]+seg[i*2+1][1]);
            seg[i][1] = seg[i*2][1];
            seg[i][2] = seg[i*2+1][2];
            seg[i][3] = 0;
        }
    }
}

void build(int i, int l, int r) {
    if(l==r) {
        cin >> an[l];
        seg[i][3]=1;
        return;
    }
    int m=(l+r)/2;
    build(i*2, l, m);
    build(i*2+1, m+1, r);
    calc(i, l, r);
}

void update(int i, int l, int r, int x, int y) {
    if(x<l||x>r) return;
    if(l==r) {
        an[x] = y;
        return;
    }
    int m=(l+r)/2;
    update(i*2, l, m, x, y);
    update(i*2+1, m+1, r, x, y);
    calc(i, l, r);
}

void query(int i, int l, int r, int s, int e) {
    if(r<s||e<l) return;
    if(s<=l&&r<=e) {
        if(seg[i][3]) {
            if(an[l-1]>an[l]) {
                ans += f(k);
                k = r-l+1;
            }
            else {
                k += r-l+1;
            }
        }
        else {
            if(an[l-1]>an[l]) {
                ans += f(k)+seg[i][0]+f(seg[i][1]);
            }
            else {
                ans += seg[i][0]+f(k+seg[i][1]);
            }
            k = seg[i][2];
        }
        return;
    }
    int m=(l+r)/2;
    query(i*2, l, m, s, e);
    query(i*2+1, m+1, r, s, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n, q, t, l, r;

    cin >> n >> q;
    build(1, 1, n);
    while(q--) {
        cin >> t >> l >> r;
        if(t==1) {
            update(1, 1, n, l, r);
        }
        else {
            ans = k = 0;
            query(1, 1, n, l, r);
            cout << ans+f(k) << '\n';
        }
    }
}
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int an[100010]{0};
int seg[300010]{0};
int n;

int init(int node, int s, int e) {
    if (s==e) return seg[node] = s;
    int mid=(s+e)/2;
    int a=init(2*node, s, mid);
    int b=init(2*node+1, mid+1, e);
    if(an[a]>=an[b]) swap(a, b);
    return seg[node] = a;
}

int query(int node, int s, int e, int l, int r) {
    if (e<l || r<s) return 0;
    if (l<=s && e<=r) return seg[node];
    int mid = (s + e) / 2;
    int a=query(2*node, s, mid, l, r);
    int b=query(2*node+1, mid+1, e, l, r);
    if(an[a]>=an[b]) swap(a, b);
    return a; 
}

int go(int l, int r) {
    if(r-l<0) return 0;
    if(r-l==0) return an[l];
    int mid=query(1, 1, n, l, r);
    int res=an[mid]*(r-l+1);
    if(l<=mid-1) res=max(res, go(l, mid-1));
    if(r>=mid+1) res=max(res, go(mid+1, r));
    return res;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        cin >> n;
        if(n==0) break;
        memset(an, 0, sizeof(an));
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        an[0] = 2000000000;
        memset(seg, 0, sizeof(seg));
        init(1,1,n);
        cout << go(1, n) << '\n';
    }
}
#include <iostream>
#include <tuple>
#include <vector>
#include <set>

typedef long long ll;
using namespace std;

vector<tuple<ll, ll, ll, ll, int>> lines;
int parent[3010]{0};
int cnt[3010]{0};

int getParent(int i) {
    if(parent[i]==i) return i;
    return parent[i] = getParent(parent[i]);
}

int unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a<b) {
        parent[b] = a;
        cnt[a] += cnt[b];
    } else if(a>b) {
        parent[a] = b;
        cnt[b] += cnt[a];
    }
}

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll a=x1*y2+x2*y3+x3*y1;
    ll b=x2*y1+x3*y2+x1*y3;
    if(a-b>0) return 1;
    else if(a-b<0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cnt[i] = 1;
        parent[i] = i;
    }
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lines.push_back({a, b, c, d, i});
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll x1, y1, x2, y2, a1, b1, a2, b2, idx1, idx2;
            tie(x1, y1, x2, y2, idx1) = lines[i];
            tie(a1, b1, a2, b2, idx2) = lines[j];
            ll res1=ccw(x1, y1, x2, y2, a1, b1);
            ll res2=ccw(x1, y1, x2, y2, a2, b2);
            ll res3=ccw(a1, b1, a2, b2, x1, y1);
            ll res4=ccw(a1, b1, a2, b2, x2, y2);
            if(res1*res2<=0) {
                if(res3*res4<=0) {
                    if(!res1&&!res2&&!res3&&!res4) {
                        if(x1>x2) {
                            swap(x1, x2);
                            swap(y1, y2);
                        }
                        if(a1>a2) {
                            swap(a1, a2);
                            swap(b1, b2);
                        }
                        if(x2<a1||x1>a2) continue;
                        if(y1>y2) {
                            swap(x1, x2);
                            swap(y1, y2);
                        }
                        if(b1>b2) {
                            swap(a1, a2);
                            swap(b1, b2);
                        }
                        if(y2<b1||y1>b2) continue;
                        unionParent(idx1, idx2);
                    } else {
                        unionParent(idx1, idx2);
                    }
                }
            }
        }
    }
    set<int> ans;
    int ans2=0;
    for(int i=0; i<n; i++) {
        ans.insert(getParent(i));
        ans2 = max(ans2, cnt[i]);
    }
    cout << ans.size() << '\n';
    cout << ans2;
}   
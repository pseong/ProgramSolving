#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, t;
map<pii, bool> v;
map<pii, bool> visi;

int calc() {
    visi.clear();
    queue<tuple<int, int, int>> que;
    que.push({0, 0, 0});
    visi[{0, 0}] = 1;
    while (!que.empty()) {
        auto f = que.front();
        que.pop();
        int a = get<0>(f);
        int b = get<1>(f);
        int cnt = get<2>(f);
        if (b >= t) return cnt;
        for (int x=a-2; x<=a+2; x++) {
            if (x < 0) continue;
            for (int y=b-2; y<=b+2; y++) {
                if (y < 0) continue;
                if (v[{x, y}] == 0) continue;
                if (visi[{x, y}]) continue;
                visi[{x, y}] = 1;
                que.push({x, y, cnt+1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> t;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[{a, b}] = 1;
    }

    cout << calc();
}
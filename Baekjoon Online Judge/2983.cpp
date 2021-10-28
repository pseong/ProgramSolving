#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

map<int, set<pii>> ps;
map<int, set<pii>> ms;
int n, k;
string s;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> s;

    int x, y;
    cin >> x >> y;
    ps[x+y].insert({x, y});
    ms[x-y].insert({x, y});
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        ps[a+b].insert({a, b});
        ms[a-b].insert({a, b});
    }
    ps[x+y].erase(ps[x+y].lower_bound({x, y}));
    ms[x-y].erase(ms[x-y].lower_bound({x, y}));

    for(int i=0; i<k; i++) {
        if(s[i]=='A') {
            auto it=ms[x-y].upper_bound({x, y});
            if(it==ms[x-y].end()) continue;
            tie(x, y) = *it;
            ms[x-y].erase(it);
            ps[x+y].erase(ps[x+y].lower_bound({x, y}));
        }
        else if(s[i]=='D') {
            auto it=ms[x-y].upper_bound({x, y});
            if(it==ms[x-y].begin()) continue;
            it--;
            tie(x, y) = *it;
            ms[x-y].erase(it);
            ps[x+y].erase(ps[x+y].lower_bound({x, y}));
        }
        else if(s[i]=='B') {
            auto it=ps[x+y].upper_bound({x, y});
            if(it==ps[x+y].end()) continue;
            tie(x, y) = *it;
            ps[x+y].erase(it);
            ms[x-y].erase(ms[x-y].lower_bound({x, y}));
        }
        else if(s[i]=='C') {
            auto it=ps[x+y].upper_bound({x, y});
            if(it==ps[x+y].begin()) continue;
            it--;
            tie(x, y) = *it;
            ps[x+y].erase(it);
            ms[x-y].erase(ms[x-y].lower_bound({x, y}));
        }
    }
    cout << x << ' ' << y;
}
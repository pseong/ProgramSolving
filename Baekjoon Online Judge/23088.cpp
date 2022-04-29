#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct prc {
    ll id, start, time, score;
};

struct comp{
    bool operator()(prc l, prc r){
        if (l.score == r.score) {
            if (l.time == r.time) {
                return l.id > r.id;
            }
            return l.time > r.time;
        }
        return l.score < r.score;
    }
};

vector<prc> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll t, p, b;
        cin >> t >> p >> b;
        v.push_back({i, t, b, p-t});
    }

    vector<ll> ans;
    priority_queue<prc, vector<prc>, comp> pq;
    ll end = 0;
    for (ll i=0; i<v.size();) {
        if (v[i].start <= end) {
            pq.push(v[i]);
            i++;
        }
        else {
            while (pq.size() && v[i].start > end) {
                ans.push_back(pq.top().id);
                end = max(end, pq.top().start) + pq.top().time;
                pq.pop();
            }
            if (v[i].start > end) end = v[i].start;
        }
    }

    while (pq.size()) {
        ans.push_back(pq.top().id);
        pq.pop();
    }

    for (ll i=0; i<ans.size(); i++) {
        cout << ans[i]+1 << ' ';
    }
}
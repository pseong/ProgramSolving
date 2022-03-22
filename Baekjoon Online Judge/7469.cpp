#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[101010], n, m;

struct Seg {
    vector<int> tree[404040];

    void merge(vector<int>& par, vector<int>& left, vector<int>& right) {
        par.clear();
        int j=0;
        for (int i=0; i<left.size();) {
            if (j < right.size()) {
                if (left[i] < right[j]) {
                    par.push_back(left[i]);
                    i++;
                }
                else {
                    par.push_back(right[j]);
                    j++;
                }
            }
            else {
                par.push_back(left[i]);
                i++;
            }
        }
        for (; j<right.size(); j++) {
            par.push_back(right[j]);
        }
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node].push_back(an[e]);
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        merge(tree[node], tree[node*2], tree[node*2+1]);
    }

    int query(int node, int s, int e, int l, int r, int k) {
        if (r<s || e<l) return 0;
        if (l<=s && e<=r) {
            return lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        };
        int mid = (s+e)/2;
        return query(node*2, s, mid, l, r, k) + query(node*2+1, mid+1, e, l, r, k);
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    seg.init(1, 1, n);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int s = -1e9;
        int e = 1e9;
        int ans = 0;
        while (s <= e) {
            int mid = (s+e)/2;
            int cal = seg.query(1, 1, n, a, b, mid);
            if (cal < c) {
                s = mid+1;
            }
            else {
                ans = mid;
                e = mid-1;
            }
        }
        cout << ans-1 << '\n';
    }
}
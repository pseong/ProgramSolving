#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> an(n+1), bn(n+1);
    set<int> a, b;
    vector<int> aord{ -1 }, bord{ -1 }, asz(n+1), bsz(n+1);
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        if (a.find(an[i]) == a.end()) aord.push_back(an[i]);
        a.insert(an[i]);
        asz[i] = a.size();
    }
    for (int i=1; i<=n; i++) {
        cin >> bn[i];
        if (b.find(bn[i]) == b.end()) bord.push_back(bn[i]);
        b.insert(bn[i]);
        bsz[i] = b.size();
    }

    vector<int> same{ -1 };
    set<int> st;
    for (int i=1; i<min(aord.size(), bord.size()); i++) {
        if (st.find(aord[i]) == st.end()) {
            st.insert(aord[i]);
        }
        else st.erase(aord[i]);
        if (st.find(bord[i]) == st.end()) {
            st.insert(bord[i]);
        }
        else st.erase(bord[i]);
        if (st.size() == 0) same.push_back(1);
        else same.push_back(0);
    }

    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int x, y, k;
        cin >> x >> y;
        if (asz[x] != bsz[y]) cout << "No\n";
        else {
            if (same[asz[x]]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
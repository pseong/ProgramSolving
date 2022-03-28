#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> m, p, ans;
int zero, one;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a < 0) m.push_back(a);
        else if (a > 1) p.push_back(a);
        else if (a == 0) zero++;
        else one++;
    }

    sort(m.begin(), m.end());
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    if (m.size() % 2) m.pop_back();
    if (p.size() % 2 && one) {
        ans.push_back(p.back());
        p.pop_back();
        one--;
    }
    ans.push_back(one/2);
    
    for (int i=0; i<(int)(p.size()-1); i+=2) {
        ans.push_back(p[i]*p[i+1]);
    }
    for (int i=0; i<(int)(m.size()-1); i+=2) {
        int temp =  (i<m.size()-1);
        ans.push_back(m[i]*m[i+1]);
    }

    int a = 0;
    for (int b : ans) {
        a += b;
    }
    cout << a;
}
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

class Stringversions {
    public:
    string create(int L, int N) {
        int ans = 1;
        int cnt = 0;
        for (; ans<=26; ans++) {
            if (ans*(ans-1)/2 >= N) break;
        }
        ans = min(ans, 26);
        for (;; cnt++) {
            if (cnt*25 + ans*(ans-1)/2 >= N) break;
        }
        if (ans + cnt > L) return "";
        int minus = cnt*25+ans*(ans-1)/2 - N;
        vector<int> v;
        for (int i=0; i<cnt; i++) v.push_back(25);
        for (int i=ans-1; i>=0; i--) v.push_back(i);
        while (v.size() < L) v.push_back(25);
        string a;
        for (int i=0; i<v.size(); i++) {
            a.push_back(v[i]+'a');
        }
        for (int i=0; i<minus; i++) {
            a[0]--;
        }
        return a;
    }
};

int main() {
    Stringversions s;
    cout << s.create(500, 120190);
}
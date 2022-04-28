#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

class Stringversions {
    public:
    string create(int L, int N) {
        int q = L / 26;
        int r = L % 26;
        string ans;
        for (int i=25; i>=0; i--) {
            for (int j=0; j<q; j++) {
                ans.push_back('a'+i);
            }
            if (r > 0) {
                ans.push_back('a'+i);
                r--;
            }
        }

        int cnt = 0;
        for (int i=0; i<ans.size(); i++) {
            for (int j=i+1; j<ans.size(); j++) {
                if (ans[i] > ans[j]) cnt++;
            }
        }
        if (cnt < N) return "";
        while (cnt != N) {
            for (int i=0; i<ans.size()-1; i++) {
                if (ans[i] > ans[i+1]) {
                    swap(ans[i], ans[i+1]);
                    cnt--;
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {
    Stringversions s;
    cout << s.create(5, 1);
}
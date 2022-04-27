#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

class TwoLineMinesweeper {
    public:
    vector<string> ans;
    vector<int> v;
    string now;

    void go(int i) {
        if (i == v.size()-1 && now[now.size()-2] != 'x') {
            ans.push_back(now.substr(1, v.size()));
            return;
        }

        vector<int> per;
        for (int k=0; k<v[i]; k++) per.push_back(1);
        while (per.size() < 3) per.push_back(0);
        sort(per.begin(), per.end());
        
        string tmp = now.substr(i-1, 3);
        do {
            bool fail = false;
            for (int j=0; j<3; j++) {
                if (per[j]) {
                    if (now[i-1+j] == '-') fail = true;
                    now[i-1+j] = '*';
                }
                else {
                    if (now[i-1+j] == '*') fail = true;
                    now[i-1+j] = '-';
                }
            }
            if (!fail) go(i+1);
            for (int j=0; j<3; j++) {
                now[i-1+j] = tmp[j];
            }
        } while(next_permutation(per.begin(), per.end()));
    }

    vector<string> solve(vector<int> firstLine) {
    	v = firstLine;
        v.insert(v.begin(), -1);
        v.push_back(-1);
        now = string(v.size(), 'x');
        now[0] = '-';
        now.back() = '-';
        go(1);
        return ans;
    }
};
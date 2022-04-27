#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

class TwoTowers {
    public:
    int maxDifference(vector<int> A, vector<int> B) {
        int a=0, b=0;
        for (int i=0; i<A.size(); i++) {
            a += max(A[i], B[i]);
            b += min(A[i], B[i]);
        }
        return a-b;
    }
};
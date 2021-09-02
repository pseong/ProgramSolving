#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    k-=5;
    if(k<0) {
        cout << 0;
        return 0;
    }
    int use[36]{0};
    string str[50];
    for(int i=0; i<n; i++) {
        cin >> str[i];
        for(int j=0; j<str[i].size(); j++) {
            use[str[i][j]-'a'] = true;
        }
    }

    int cnt=0;
    for(int i=0; i<36; i++) {
        if(i==0 || i==2 || i==8 || i==13 || i==19) continue;
        if(use[i]) {
            use[i]=cnt;
            cnt++;
        }
    }

    vector<int> v;
    for(int i=0; i<cnt-k; i++) {
        v.push_back(0);
    }
    for(int i=0; i<k; i++) {
        v.push_back(1);
    }
    int ans=0;
    do {
        int res=0;
        for(int i=0; i<n; i++) {
            bool ok=true;
            for(int j=0; j<str[i].size(); j++) {
                int inp=str[i][j]-'a';
                if(inp==0 || inp==2 || inp==8 || inp==13 || inp==19) continue;
                if(!v[use[inp]]) {
                    ok = false;
                    break;
                }
            }
            if(ok) res++;
        }
        ans = max(ans, res);
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;
}
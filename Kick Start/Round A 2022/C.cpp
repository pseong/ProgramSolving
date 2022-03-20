#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
string s;
bool ans;

bool pal(int a, int b, int idx) {
    while (a>=0 && b<=idx) {
        if (s[a] == s[b]) {
            if (b-a >= 4) return true;
            a--;
            b++;
        }
        else break;
    }
    return false;
}

bool test(int idx) {
    if (!pal(idx-2, idx-2, idx) && !pal(idx-3, idx-2, idx)) return true;
    else return false;
}

void dfs(int idx) {
    if (ans) return;
    if (idx == s.size()) {
        ans = true;
        return;
    }
    if (s[idx] != '?') {
        if (test(idx)) {
            dfs(idx+1);
        }
        return;
    }
    s[idx] = '0';
    if (test(idx)) {
        dfs(idx+1);
    }
    s[idx] = '1';
    if (test(idx)) {
        dfs(idx+1);
    }
    s[idx] = '?';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for (int i=1; i<=T; i++) {
        ans = false;
        cin >> n >> s;
        if (n < 5) {
            cout << "Case #" << i << ": " << "POSSIBLE" << '\n';
        }
        else {
            dfs(0);
            if (ans) {
                cout << "Case #" << i << ": " << "POSSIBLE" << '\n';
            }
            else {
                cout << "Case #" << i << ": " << "IMPOSSIBLE" << '\n';
            }
        }
    }
}
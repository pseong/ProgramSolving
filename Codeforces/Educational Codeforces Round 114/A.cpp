#include <iostream>
#include <vector>

using namespace std;

vector<char> v;
int n;
int cnt=0;
void go(int idx, int open, int close) {
    if(cnt==n) return;
    if(idx==n*2) {
        for(char i : v) cout << i;
        cout << '\n';
        cnt++;
        return;
    }
    if(open==n) {
        for(char i : v) cout << i;
        for(int i=0; i<n-close; i++) cout << ')';
        cout << '\n';
        cnt++;
        return;
    }
    if(open<=n) {
        v.push_back('(');
        go(idx+1, open+1, close);
        v.pop_back();
    }
    if(open>close) {
        v.push_back(')');
        go(idx+1, open, close+1);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        cnt = 0;
        go(0, 0, 0);
    }
}
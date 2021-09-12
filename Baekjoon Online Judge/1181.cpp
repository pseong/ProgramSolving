#include <bits/stdc++.h>

using namespace std;

bool cmp(string& s1, string& s2) {
    if(s1.size() != s2.size()) return s1.size() < s2.size();
    else return s1 < s2;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> vs;
    while(n--) {
        string s;
        cin >> s;
        vs.push_back(s);
    }

    sort(vs.begin(), vs.end(), cmp);

    string pre = "A";
    for(const string& s : vs) {
        if(pre == s) continue;
        cout << s << '\n';
        pre = s;
    }
}
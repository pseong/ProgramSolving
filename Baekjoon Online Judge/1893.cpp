#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

string a, p, s, ss;
vector<int> table;
map<char, int> char_to_int;
map<int, char> int_to_char;

void makeTable() {
    int j = 0;
    for (int i=1; i<p.size(); i++) {
        while (j>0 && p[j] != p[i]) {
            j = table[j-1];
        }
        if (p[j] == p[i]) {
            table[i] = ++j;
        }
    }
}

bool KMP() {
    int cnt = 0;
    int j = 0;
    for (int i=0; i<s.size(); i++) {
        while (j>0 && s[i] != p[j]) {
            j = table[j-1];
        }
        if (s[i] == p[j]) {
            if (j == p.size()-1) {
                cnt++;
                j = table[j];
            }
            else {
                j++;
            }
        }
    }
    if (cnt == 1) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> a >> p >> ss;
        char_to_int.clear();
        int_to_char.clear();
        for (int i=0; i<a.size(); i++) {
            char_to_int[a[i]] = i;
            int_to_char[i] = a[i];
        }
        table.resize(p.size());
        fill(table.begin(), table.end(), 0);
        makeTable();
        vector<int> ans;
        for (int i=0; i<a.size(); i++) {
            s.clear();
            for (int j=0; j<ss.size(); j++) {
                int tmp = char_to_int[ss[j]]-i;
                if (tmp < 0) tmp += a.size();
                s.push_back(int_to_char[tmp]);
            }
            if (KMP()) ans.push_back(i);
        }
        if (ans.size() == 0) {
            cout << "no solution\n";
        }
        else if (ans.size() == 1) {
            cout << "unique: " << ans.front() << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (int i : ans) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
}
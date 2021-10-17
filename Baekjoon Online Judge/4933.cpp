#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int parent[100];
vector<int> nodes;
int parent2[100];
vector<int> nodes2;
stack<string> st;
stack<string> st2;

void dfs(int node, int par) {
    parent[node] = par;
    if(st.empty()) return;
    string s=st.top();
    st.pop();
    if(s!="nil") {
        nodes.push_back(s[0]);
        dfs(s[0], node);
    }
    if(st.empty()) return;
    s=st.top();
    st.pop();
    if(s!="nil") {
        nodes.push_back(s[0]);
        dfs(s[0], node);
    }
}

void dfs2(int node, int par) {
    parent2[node] = par;
    if(st2.empty()) return;
    string s=st2.top();
    st2.pop();
    if(s!="nil") {
        nodes2.push_back(s[0]);
        dfs2(s[0], node);
    }
    if(st2.empty()) return;
    s=st2.top();
    st2.pop();
    if(s!="nil") {
        nodes2.push_back(s[0]);
        dfs2(s[0], node);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        string s;
        while(true) {
            cin >> s;
            if(s=="end") break;
            st.push(s);
        }
        while(true) {
            cin >> s;
            if(s=="end") break;
            st2.push(s);
        }
        string str=st.top();
        st.pop();
        if(str!="nil") {
            nodes.push_back(str[0]);
            dfs(str[0], 0);
        }
        str=st2.top();
        st2.pop();
        if(str!="nil") {
            nodes2.push_back(str[0]);
            dfs2(str[0], 0);
        }
        sort(nodes.begin(), nodes.end());
        sort(nodes2.begin(), nodes2.end());
        bool fail=false;
        if(nodes!=nodes2) {
            fail = true;
        }
        for(int i : nodes) {
            if(parent[i]!=parent2[i]) {
                fail = true;
            }
        }
        if(fail) cout << "false\n";
        else cout << "true\n";
        memset(parent, 0, sizeof(parent));
        memset(parent2, 0, sizeof(parent2));
        nodes.clear();
        nodes2.clear();
    }
}
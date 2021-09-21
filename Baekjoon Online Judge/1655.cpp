#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    priority_queue<int> mx;
    priority_queue<int> mn;
    int n;
    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        if(mx.empty()) {
            mx.push(a);
        } else if(mn.empty()) {
            if(mx.top()<=a) mn.push(-a);
            else {
                mn.push(-mx.top());
                mx.pop();
                mx.push(a);
            }
        } else {
            int mx_t=mx.top();
            int mn_t=-mn.top();
            if(a<=mx_t) {
                mx.push(a);
            } 
            else if(a>=mn_t) {
                mn.push(-a);
            } 
            else mn.push(-a);
            if(mn.size() > mx.size()) {
                mx.push(-mn.top());
                mn.pop();
            }
            else if(mn.size()+1 < mx.size()) {
                mn.push(-mx.top());
                mx.pop();
            }
        }
        int aaa=mx.top();
        cout << mx.top() << '\n';
    }
}
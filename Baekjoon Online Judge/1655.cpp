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
        if(mx.size()<mn.size()+1) {
            mx.push(a);
        } else {
            mn.push(-a);
        }
        if(!mn.empty() && mx.top() > -mn.top()) {
            int c=mx.top();
            int d=-mn.top();
            mx.pop();
            mn.pop();
            mx.push(d);
            mn.push(-c);
        }
        int aaa=mx.top();
        cout << mx.top() << '\n';
    }
}
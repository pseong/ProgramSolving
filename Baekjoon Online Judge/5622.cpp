#include <iostream>
#include <string>

using namespace std;

int an[300]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int sum=0;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='S' || str[i]=='V' ||
            str[i]=='Y' || str[i]=='Z') sum -= 1;
        sum += (str[i]-'A')/3+3;
    }
    cout << sum;
}
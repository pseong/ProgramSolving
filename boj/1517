#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[500010]{ 0 };
ll sorted[500010]{ 0 };
ll ans = 0;

void merge(ll m, ll mid, ll n) {
    ll i = m;
    ll j = mid + 1;
    ll k = m;

    ll cnt = 0;

    while(i <= mid && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            ans += cnt;
            i++;
        } else {
            sorted[k] = a[j];
            cnt++;
            j++;
        }
        k++;
    }   
    if(i > mid) {
        for(ll t = j; t <= n; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else {
        for(ll t = i; t <= mid; t++) {
            sorted[k] = a[t];
            ans += cnt;
            k++;
        }
    }
    for(ll t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(ll m, ll n) {
    if(m < n) {
        ll mid = (m + n) / 2;
        mergeSort(m, mid);
        mergeSort(mid + 1, n);
        merge(m, mid, n);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mergeSort(1, n);

    cout << ans;
}
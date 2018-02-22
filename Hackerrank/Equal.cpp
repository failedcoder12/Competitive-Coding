//https://www.hackerrank.com/challenges/equal/problem

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll fans = 0;
        for (ll i = n - 1; i >= 1; i--) {
            ll c, ans = 0;
            c = a[i] - a[0];
            ans += c / 5;
            c = c % 5;
            ans += c / 2;
            c = c % 2;
            ans += c;
            fans += ans;
        }
ll fans2 = 0;
        for (ll i = n - 1; i >= 0; i--) {
            ll c, ans = 0;
            c = a[i] - a[0]+1;
            ans += c / 5;
            c = c % 5;
            ans += c / 2;
            c = c % 2;
            ans += c;
            fans2 += ans;
        }
        
ll fans3 = 0;
        for (ll i = n - 1; i >= 0; i--) {
            ll c, ans = 0;
            c = a[i] - a[0]+2;
            ans += c / 5;
            c = c % 5;
            ans += c / 2;
            c = c % 2;
            ans += c;
            fans3 += ans;
        }
        
ll fans4 = 0;
        for (ll i = n - 1; i >= 0; i--) {
            ll c, ans = 0;
            c = a[i] - a[0]+5;
            ans += c / 5;
            c = c % 5;
            ans += c / 2;
            c = c % 2;
            ans += c;
            fans4 += ans;
        }
        cout << min(fans,min(fans2,min(fans3,fans4))) << endl;
    }
}
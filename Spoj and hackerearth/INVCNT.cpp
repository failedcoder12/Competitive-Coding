// http://www.spoj.com/problems/INVCNT/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void update(ll i,ll inc,ll n,ll BIT[]){
    while(i<=n){
        BIT[i]+=inc;
        i+=(i&(-i));
    }
}

ll query(ll i,ll BIT[]){
    ll ans = 0;
    while(i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        ll a[1000000];
        ll BIT[1000000];
        cin >> n;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans = 0;
        for (ll i = n; i >= 1; i--) {
            ans += query(a[i] - 1,BIT);
            update(a[i], 1, n,BIT);
        }
        cout << ans << endl;
    }
}
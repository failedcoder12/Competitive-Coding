
//https://www.codechef.com/DEC17/problems/CHEFHAM/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        ll a[t],aa[t],aaa[t];
        for (ll j = 0; j < t; j++) {
            cin >> a[j];
            aa[j] = a[j];
        }
        ll maxc=-1;
        for(ll p=0;p<4;p++) {
            for (ll k = 0; k < t - 1; k++) {
                ll tt = a[k];
                a[k] = a[k + 1];
                a[k + 1] = tt;
            }
            ll c = 0;
            for (ll j = 0; j < t; j++) {
                if (aa[j] != a[j])
                    c++;
            }
            if(c>maxc){
                maxc = c;
                for (ll j = 0; j < t; j++) {
                    aaa[j] = a[j];
                }
            }
        }
        cout<<maxc<<endl;
        for(ll j=0;j<t;j++){
            cout<<aaa[j]<<" ";
        }
        cout<<endl;
    }
}  
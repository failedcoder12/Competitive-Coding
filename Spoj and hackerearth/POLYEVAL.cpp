// http://www.spoj.com/problems/POLEVAL/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
   
ll horners(ll a[],ll n,ll x){
    ll result = a[0];
    for(ll i=1;i<n;i++){
        result = result*x + a[i];
    }
    return result;
}
 
int main() {
 
    ll casse = 1;
    while(1){
        ll n;
        cin>>n;
        if(n == -1){
            return 0;
        }
        cout<<"Case "<<casse++<<":"<<endl;
        n=n+1;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll k;
        cin>>k;
        for(ll i=0;i<k;i++) {
            ll x;
            cin>>x;
            cout << horners(a, n, x)<<endl;
        }
    }
} 
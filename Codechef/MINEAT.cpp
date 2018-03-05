// https://www.codechef.com/MARCH18B/problems/MINEAT/?
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
bool possible(ll a[],ll h,ll k,ll n){
    ll sum = 0;
  for(ll i=0;i<n;i++){
      sum+=a[i]/k;
      sum+=a[i]%k==0?0:1;
  }  
    if(sum <= h)
        return 1;
    return 0;
}
 
ll binary (ll a[],ll s,ll e,ll h,ll n){
    if(s>=e){
            return e;
    }
    ll m = s+(e-s)/2;
    if(possible(a,h,m,n)){
        return binary(a,s,m,h,n);
    }else {
        return binary(a,m+1,e,h,n);
    }
}
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,h;
        cin>>n>>h;
        ll a[n];
        ll e = LONG_LONG_MIN;
        ll s = LONG_LONG_MAX;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<s){
                s = a[i];
            }
            if(a[i]>e){
                e = a[i];
            }
        }
 
        cout<<binary(a,1,e,h,n)<<endl;
    }
}
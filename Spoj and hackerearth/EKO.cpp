// http://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
bool possible(ll a[],ll n,ll k,ll m){
    ll count = 0;
    for(ll i=0;i<n;i++){
        if(a[i]>=m){
            count+=(a[i]-m);
        }
    }
    if(count>=k){
        return true;
    }
    return false;
}
 
ll binary(ll a[],ll s,ll e,ll n,ll k){
    if(s>=e){
        if(possible(a,n,k,e))
        return e;
        return e-1;
    }
    ll m = s+ (e-s)/2;
    if(possible(a,n,k,m)){
        return binary(a,m+1,e,n,k);
    }else {
        return binary(a,s,m,n,k);
    }
}
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll k;
    cin>>k;
    ll maxx = INT_MIN;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        maxx = max(a[i],maxx);
    }
   cout<<binary(a,0,maxx,n,k)<<endl;
}
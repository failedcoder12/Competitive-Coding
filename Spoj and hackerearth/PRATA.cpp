// http://www.spoj.com/problems/PRATA/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool check(ll a[],ll m,ll p,ll n){
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum += ((-1 + (sqrt((1+(8*m/a[i])))))/2);
    }
    return sum >= p;
}

ll binary(ll a[],ll s,ll e,ll p,ll n){
    if(s>=e){
        return e;
    }
    ll m = s+(e-s)/2;
    if(check(a,m,p,n)){
        return binary(a,s,m,p,n);
    }else {
        return binary(a,m+1,e,p,n);
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll p;
        cin>>p;
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<binary(a, 0,p*(p+1)/2*a[0], p, n)<<endl;
    }
}
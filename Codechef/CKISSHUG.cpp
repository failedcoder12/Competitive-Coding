// https://www.codechef.com/problems/CKISSHUG

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
 
ll power(ll x,ll y){
    ll temp;
    if(y==0){
        return 1;
    }
    temp = power(x,y/2);
    if(y%2==0){
        return (temp*temp)%MOD;
    }else {
        if(y>0){
            return (((x*temp)%MOD)*temp)%MOD;
        }else {
            return ((temp*temp)%MOD/x)%MOD;
        }
    }
}
 
int main(){
 
 
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans;
        if(n&1){
            ans = power(2,(n+1)/2+1) - 2;
        }else {
            ans = (3*power(2,(n/2)))%MOD-2;
        }
        cout<<ans<<endl;
    }
 
}
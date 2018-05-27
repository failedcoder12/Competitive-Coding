// https://www.codechef.com/LOCMAY18/problems/DSERIES

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
 
ll modInverse(ll a,ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
   if (x < 0)
        x += m0;
 
    return x;
}
int main(){
    ll q;
    cin>>q;
    while(q--){
        ll n,t;
        cin>>n>>t;
        n = n%MOD;
        ll ans = 1;
        for(ll i=(1);i<=(t+1);i++){
            ans = (ans * (n+i)%MOD)%MOD;
        }
 
        ans = (ans*modInverse(t+1,MOD))%MOD;
        
        ll tan = 1;
        for(ll i=1;i<=t;i++){
            tan = (tan*i)%MOD;
        }
        
        cout<<(ans-tan + MOD)%MOD<<endl;
    }
} 
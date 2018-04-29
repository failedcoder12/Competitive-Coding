// https://www.codechef.com/LOCAPR18/problems/PERFNEC/
        
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll a[5];
ll b[5];
unordered_map<ll,ll> m;
ll find_min(ll x,ll y){
    
    if(x<0){
        return 99999999;
    }
    if(x==0){
        if(y == 0)
            return 0;
        return 99999999;
    }
    if(m.count((y+2001)*1000 + x)){
        return m[(y+2001)*1000 + x];
    }
    
    ll x0 = find_min(x-1,y+2) + a[0];
    ll x1 = find_min(x-1,y+1) + a[1];
    ll x2 = find_min(x-1,y) + a[2];
    ll x3 = find_min(x-1,y-1) + a[3];
    ll x4 = find_min(x-1,y-2) + a[4];
    m[(y+2001)*1000 + x] = min(x0,min(x1,min(x2,min(x3,x4))));
    return m[(y+2001)*1000 + x];
}
 
int main(){
    b[0] = -2;b[1] = -1;b[2] = 0;b[3] = 1;b[4] = 2;
    for(ll i=0;i<5;i++){
        cin>>a[i];
    }
    ll q;
    
    cin>>q;
    
    for(ll i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        ll ans = find_min(x,y);
        if(ans >= 99999999){
            cout<<-1<<endl;
        }else {
            cout<<ans<<endl;
        }
    }
}   
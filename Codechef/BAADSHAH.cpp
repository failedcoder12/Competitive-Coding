// https://www.codechef.com/problems/BAADSHAH

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll bit[100003];
 
ll siz = 100003;
void update(ll i,ll val){
    while(i<= siz){
        bit[i] += val;
        i += (i & -i);
    }
}
 
ll query(ll i){
    ll ans = 0;
    while(i>0){
        ans+=bit[i];
        i-= (i &-i);
    }
    return ans;
}
 
ll binary(ll s,ll e,ll val){
    if(s>=e){
        if(query(e)== val){
            return e;
        }
        return -1;
    }
    ll m = s + (e-s)/2;
    if(query(m)>=val){
        return binary(s,m,val);
    }else {
        return binary(m+1,e,val);
    }
}
 
 
int main(){
    ll n,q;
    cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i]);
    }
 
    for(ll i=0;i<q;i++){
        ll type;
        cin>> type;
        if(type == 1){
            ll l,x;
            cin>>l>>x;
            update(l,x-a[l]);
            a[l] = x;
        }else {
            ll val;
            cin>>val;
            ll b = binary(1,n+1,val);
            if(b!=-1){
                cout<<"Found "<<b<<endl;
            }else {
                cout<<"Not Found"<<endl;
            }
        }
    }
}
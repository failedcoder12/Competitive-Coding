// https://www.codechef.com/MARCH18B/problems/MINVOTE

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
ll suffix[100001];
ll BITr[100001];
ll BITl[100001];
void update1(ll i,ll val){
    while(i<=100001){
        BITr[i] += val;
        i += (i & -i);
    }
}
 
void updatesum1(ll l,ll r,ll val){
    update1(l,val);
    update1(r+1,-val);
}
 
ll query1(ll i){
    ll sum = 0;
    while(i>0){
        sum += BITr[i];
        i -= (i & -i);
    }
    return sum;
}
void update2(ll i,ll val){
    while(i<=100001){
        BITl[i] += val;
        i += (i & -i);
    }
}
 
void updatesum2(ll l,ll r,ll val){
    update2(l,val);
    update2(r+1,-val);
}
 
ll query2(ll i){
    ll sum = 0;
    while(i>0){
        sum += BITl[i];
        i -= (i & -i);
    }
    return sum;
}
void updatesuffix(ll i,ll val){
    while(i<=100001){
        suffix[i] += val;
        i+= (i & -i);
    }
}
 
ll querysuffix(ll i){
    ll ans = 0;
    while(i>0){
        ans+=suffix[i];
        i-=(i & -i);
    }
    return ans;
}
 
ll binarysuff(ll s,ll e,ll val){
    if(s>=e){
 
        return e;
    }
    ll m = s+(e-s)/2;
    if(querysuffix(m)>val){
        return binarysuff(s,m,val);
    }else {
        return binarysuff(m+1,e,val);
    }
}
 
 
int main(){
    ll t;
    cin>>t;
    while(t--) {
        memset(suffix,0, sizeof(suffix));
        memset(BITl,0, sizeof(BITl));
        memset(BITr,0, sizeof(BITr));
        ll n;
        cin >> n;
        ll a[n+1];
        ll r[n+1];
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
            r[n+1-i] = a[i];
            updatesuffix(i,a[i]);
 
        }
        ll ans[n+1] = {0};
 
        for(ll i=1;i<=n;i++){
            updatesuffix(i,-a[i]);
            ll ansleft = binarysuff(i+1,n+2,a[i])-1;
            updatesum1(i+1,ansleft+1,1);
        }
 
        memset(suffix,0, sizeof(suffix));
        for (ll i = 1; i <= n; i++) {
            updatesuffix(i,r[i]);
        }
        for(ll i=1;i<=n;i++){
            updatesuffix(i,-r[i]);
            ll ansleft = binarysuff(i+1,n+2,r[i])-1;
            updatesum2(i+1,ansleft+1,1);
 
        }
        for(ll i=1;i<=n;i++){
            ans[i] = query1(i) + query2(n-i+1);
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
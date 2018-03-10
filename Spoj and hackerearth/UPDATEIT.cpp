// http://www.spoj.com/problems/UPDATEIT/

#include <bits/stdc++.h>
using namespace std;
#define ll int

void update(ll i,ll val,ll BIT[],ll n){
    while(i<=n){
        BIT[i] += val;
        i += (i & -i);
    }
}

void updatesum(ll l,ll r,ll val,ll BIT[],ll n){
    update(l,val,BIT,n);
    update(r+1,-val,BIT,n);
}

ll query(ll i,ll BIT[]){
    ll sum = 0;
    while(i>0){
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int main(){
    ll t;
    scanf("%d",&t);
    while(t--){
        ll n,u;
        scanf("%d",&n);
        scanf("%d",&u);
        ll BIT[n+5] = {0};

        for(ll i=0;i<u;i++){
            ll l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            updatesum(l+1,r+1,val,BIT,n);
        }
        ll q;
        cin>>q;
        for(ll i=0;i<q;i++){
            ll qq;
            scanf("%d",&qq);
            printf("%d\n",query(qq+1,BIT));
        }
    }
}
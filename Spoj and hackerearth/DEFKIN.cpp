//http://www.spoj.com/problems/DEFKIN/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll xm,ym,n;
        cin>>xm>>ym>>n;
        set<ll> x;
        set<ll>y;
        x.insert(xm+1);
        y.insert(ym+1);
        for(ll i=0;i<n;i++){
            ll xo,yo;
            cin>>xo>>yo;
            x.insert(xo);
            y.insert(yo);
        }
        ll maxx=INT_MIN,maxy=INT_MIN;
        ll p = 0;
        for(auto xx:x){
            maxx = max(xx-p-1,maxx);
            p = xx;
        }
        p = 0;
        for(auto yy:y){
            maxy = max(yy-p-1,maxy);
            p = yy;
        }
        // cout<<maxx<<" "<<maxy<<endl;
        cout<<maxx*maxy<<endl;
    }
}
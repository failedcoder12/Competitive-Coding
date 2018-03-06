// http://www.spoj.com/problems/CTRICK/

    #include <bits/stdc++.h>
    using namespace std;
    #define ll int
    #define MAX 20500
    ll bit[MAX+1];
     
    void update(ll i,ll val){
        while(i<=MAX){
            bit[i] += val;
            i+= (i & -i);
        }
    }
     
    ll query(ll i){
        ll sum = 0;
        while(i>0){
            sum+=bit[i];
            i-= (i & -i);
        }
        return sum;
    }
     
    ll binary(ll s,ll e,ll l){
        if(s>=e){
            return e;
        }
        ll m = s + (e-s)/2;
        if(query(m)>=l){
            return binary(s,m,l);
        }else {
            return binary(m+1,e,l);
        }
    }
     
    int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            for(ll i=1;i<=n;i++){
                update(i,1);
            }
            ll ans[n+1];
            ll l = 1;ll e = n;
            for(ll i=1;i<=n;i++){
                l = (l+i)%(e);
                if(l==0){
                    l = e;
                }
                e--;
                ll position = binary(1,n,l);
                ans[position] = i;
                update(position,-1);
            }
            for(ll i=1;i<=n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    } 
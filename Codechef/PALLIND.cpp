    // https://www.codechef.com/LOCAPR18/problems/PALLIND
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define MOD 1000000007
    ll power(ll x,ll y){
        if(y == 0){
            return 1;
        }
        ll p = power(x,y/2)%MOD;
        p = (p*p)%MOD;
        return (y%2 == 0)?p:(x*p)%MOD;
    }
     
     
    int main(){
        
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll n1 = n/2;
            ll pr = power(26,n1);
            pr = (pr-1+MOD)%MOD;
            pr = (2*(pr * (power(25,MOD-2)))%MOD)%MOD;
            pr = ((pr*power(power(26,n1),MOD-2))%MOD + 1)%MOD;
            if(n%2 == 0){
                pr = (pr - power(power(26,n1),MOD-2)+MOD)%MOD;
            }
            pr = (pr)%MOD;
            cout<<pr<<endl;
        }
    } 
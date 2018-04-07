// https://www.codechef.com/APRIL18B/problems/AVGPR

    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long int
     
     
    int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            ll a[100002];
            memset(a,0, sizeof(a));
            for(ll i=0;i<n;i++){
                ll x;
                cin>>x;
                x = x+1001;
                a[x]++;
            }
            ll count = 0;
            for(ll i=1;i<2002;i++){
                if(a[i]>0){
                    ll p = 2*i;
                    for(ll j=1;j<p;j++){
                        if(a[j] > 0){
                            if(p-j>=0 && a[p-j]>0){
                                if(p-j == j){
                                    
                                }else {
                                    count += (a[j]*a[p-j]);
                                    // cout<<j<<" "<<p-j<<endl;
                                }
                            }
                        }
                    }
                }
            }
            // cout<<count<<endl;
            count = count/2;
            for(ll i=1;i<2002;i++){
                if(a[i]>1){
                    count+=(a[i]*(a[i]-1)/2);
                }
            }
            cout<<count<<endl;
        }
    } 
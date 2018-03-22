// https://www.codechef.com/COOK77/problems/CHEFINS

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define MAX 200005
     
    bool possible[MAX];
     
    int main(){
        ll n,k,q;
        cin>>n>>k>>q;
        ll a[n+1];
        for(ll i=1;i<=k;i++){
            cin>>a[i];
        }
     
        sort(a+1,a+k+1);
        possible[0] = true;
        for(ll i=1;i<=k;i++){
            ll val = a[i];
            if(possible[val]){
                continue;
            }
            for(ll j=0;j+val<MAX;j++){
                if(possible[j]){
                    possible[j+val] = true;
                }
            }
        }
     
        for(ll i=0;i<q;i++){
            ll quer;
            cin>>quer;
            if(possible[quer]){
                cout<<"Yes"<<endl;
            }else {
                cout<<"No"<<endl;
            }
        }
     
    } 
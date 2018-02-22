#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll i=1;i<n+1;i++){
            string s;
            cin>>s;
            cin>>a[i];
        }
        ll sum = 0;
        sort(a+1,a+n+1);
        for(ll i=1;i<n+1;i++){
            sum+=abs(a[i] - i);
        }
        cout<<sum<<endl;
    }

}